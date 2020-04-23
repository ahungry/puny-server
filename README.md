# Puny Server

Small cross platform web server written in C that will run Janet code.

# Usage

Just build it (make).  To run the .so variant without installing the
.so globally:

```sh
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./puny-server.so.bin
```

This will just serve a hardcoded version response until you define
your own callback in C or janet.

To set up the janet part so that you can launch `janet main.janet`,
just run (after the initial make) the `jpm build` command.

You can edit `handler` to see different response formats etc.

# Benchmarking

siege -r100 -c100 http://127.0.0.1:12003

# License

GPLv3

Copyright 2020 Matthew Carter <m@ahungry.com>
