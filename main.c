// Copyright (C) 2020 Matthew Carter <m@ahungry.com>

#include "puny-server.h"

/* ------------------------------------------------------------ */
/* The server process's one-off setup code                      */
/* ------------------------------------------------------------ */

int
main(__attribute__((unused))int argc,
     __attribute__((unused))char *argv[])
{
  signal (SIGINT, sigint_handler);

  int sock = make_sock (PORT_STR);
  set_server_sock (sock);

  fprintf (stderr, "Listening on %s\n", PORT_STR);

  /* Serve the listening socket until killed */
  take_connections_forever (sock);

  return EXIT_SUCCESS;
}
