# Dungeoneerz
# Copyright(c) 2015 Samuel "MrOverkill" Meyers

VERSION=$1

if [ -a dungeoneerz-linux-${VERSION}.zip ]
then 
    rm dungeoneerz-linux-${VERSION}.zip
fi

pushd dist

zip -ry -9 ../dungeoneerz-linux-${VERSION}.zip dungeoneerz

popd
