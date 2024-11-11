#!/bin/bash

# Compile
export CC="gcc"
export CFLAGS="-Wall -Wextra -Werror -g -fsanitize=address"
export CLIBS="-Llibs -lft -lftprintf"
export CINCLUDES="-Iincludes"

export SERVER_FILES=$(find server -name "*.c")
export SERVER="server.out"
$CC $CFLAGS $SERVER_FILES -o $SERVER $CINCLUDES $CLIBS

export CLIENT_FILES=$(find client -name "*.c")
export CLIENT="client.out"
$CC $CFLAGS $CLIENT_FILES -o $CLIENT $CINCLUDES $CLIBS

# Run Server
./$SERVER