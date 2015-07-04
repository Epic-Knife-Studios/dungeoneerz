# Dungeoneerz
# Copyright(c) 2015 Samuel "MrOverkill" Meyers

if [ -a dist ]
then
    rm -rf dist
fi

mkdir dist
mkdir dist/dungeoneerz
mkdir dist/dungeoneerz/lib

cp build/dungeon dist/dungeoneerz/
cp dependencies/SFML/lib/* dist/dungeoneerz/lib/
cp build/lib/* dist/dungeoneerz/lib/
cp build/scripts/osx-run.sh dist/dungeoneerz/run.sh

chmod +x dist/dungeoneerz/run.sh
