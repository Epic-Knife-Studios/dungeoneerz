# Dungeoneerz
# Copyright(c) 2015 Samuel "MrOverkill" Meyers

if [ -a dist ]
then
    rm -rf dist
fi

mkdir dist
mkdir dist/dungeoneerz
mkdir dist/dungeoneerz/lib
mkdir dist/dungeoneerz/source

cp build/dungeon.out dist/dungeoneerz/
cp build/lib/* dist/dungeoneerz/lib/
cp build/scripts/linux-run.sh dist/dungeoneerz/run.sh
cp -rf src dist/dungeoneerz/source/src
cp -rf include dist/dungeoneerz/source/include

chmod +x dist/dungeoneerz/run.sh
