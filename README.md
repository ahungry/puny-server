# Puny Server

Small web sever written in C that will run Janet code.

Probably aiming to be cross platform.

# Usage

Just build it (make).  To run the .so variant without installing the
.so globally:

```sh
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./puny-server.so.bin
```

# Benchmarking

siege -r100 -c100 http://127.0.0.1:12003

# About

Copyright 2020 Matthew Carter <m@ahungry.com>
