# Dungeoneerz
# Copyright(c) 2015 Samuel "MrOverkill" Meyers

#!/bin/sh

export CFLAGS="-c -fPIC -DDOS=OSX -Iinclude ${4}"

echo "[${3}] Build : ${2}"

g++ ${CFLAGS} ${1} -o ${2}
