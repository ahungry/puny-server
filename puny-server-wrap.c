// Copyright (C) 2020 Matthew Carter <m@ahungry.com>

#include <janet.h>
#include "puny-server.h"

Janet handler;

char *
janet_universal_cb (char *request)
{
  JanetTable *env;
  janet_init ();
  env = janet_core_env (NULL);

  JanetArray *args;

  const uint8_t *s = janet_string ((unsigned char *) request, strlen (request));

  args = janet_array (1);
  janet_array_push (args, janet_wrap_string (s));

  char *embed = malloc (200 + strlen (request));

  sprintf (embed, "(import handler :as h) (h/main \"%s\")", request);

  Janet *out = malloc (1);
  janet_dostring (env, embed, "main", out);
  janet_deinit ();

  const char *result = janet_getcstring (out, 0);

  free (out);
  free (embed);

  return (char *) result;
}

static Janet
puny_server_start_wrap (int32_t argc, Janet *argv)
{
  janet_fixarity (argc, 1);

  JanetFunction *f = janet_getfunction (argv, 0);
  handler = janet_wrap_function (f);

  int sock = make_sock ();
  server_sock = sock;
  callback = janet_universal_cb;

  fprintf (stderr, "Listening on 12003\n");

  /* Serve the listening socket until killed */
  take_connections_forever (sock);

  return janet_wrap_nil ();
}

static const JanetReg
puny_server_cfuns[] = {
  {"start", puny_server_start_wrap, "Start the server"},
  {NULL,NULL,NULL}
};

JANET_MODULE_ENTRY (JanetTable *env) {
  janet_cfuns (env, "puny-server", puny_server_cfuns);
}
