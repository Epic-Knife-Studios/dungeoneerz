# Dungeoneerz
# Copyright(c) 2015 Samuel "MrOverkill" Meyers

VERSION=$1

if [ -a dungeoneerz-osx-${VERSION}.zip ]
then
    rm dungeoneerz-osx-${VERSION}.zip
fi

pushd dist

zip -ry -9 ../dungeoneerz-osx-${VERSION}.zip dungeoneerz

popd
