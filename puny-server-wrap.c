// Copyright (C) 2020 Matthew Carter <m@ahungry.com>

#include <janet.h>
#include "puny-server.h"

JanetFunction *handler;

static int
janet_universal_cb (char *request)
{
  JanetArray *args;

  const uint8_t *s = janet_string ((unsigned char *) request, strlen (request));

  args = janet_array (1);
  janet_array_push (args, janet_wrap_string (s));

  Janet res = janet_call (handler, 1, args->data);

  return (int) janet_unwrap_integer (res);
}

static Janet
puny_server_start_wrap (int32_t argc, Janet *argv)
{
  janet_fixarity (argc, 1);

  JanetFunction *f = janet_getfunction (argv, 0);
  handler = f;

  int sock = make_sock ();
  server_sock = sock;
  callback = janet_universal_cb ();

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
