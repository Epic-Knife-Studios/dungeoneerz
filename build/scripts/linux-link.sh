# Dungeoneerz
# Copyright(c) 2015 Samuel "MrOverkill" Meyers

#!/bin/sh

echo "[${3}] Link : ${2}"
g++ ${1} -o ${2} -Lbuild/lib $4
