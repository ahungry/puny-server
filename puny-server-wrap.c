// Copyright (C) 2020 Matthew Carter <m@ahungry.com>

#include <janet.h>
#include "puny-server.h"

/* ------------------------------------------------------------ */
/* The server process's one-off setup code                      */
/* ------------------------------------------------------------ */

static Janet
puny_server_start_wrap (int32_t argc, Janet *argv)
{
  janet_fixarity (argc, 0);

  int sock = make_sock ();
  server_sock = sock;

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
