# Dungeoneerz
# Copyright(c) 2015 Samuel "MrOverkill" Meyers

if [ -a dist ]
then
    rm -rf dist
fi

mkdir dist
mkdir dist/dungeoneerz
mkdir dist/dungeoneerz/lib

cp build/dungeon.out dist/dungeoneerz/
cp dependencies/SFML/lib/* dist/dungeoneerz/lib/
cp build/lib/* dist/dungeoneerz/lib/
cp build/scripts/linux-run.sh dist/dungeoneerz/run.sh

chmod +x dist/dungeoneerz/run.sh
