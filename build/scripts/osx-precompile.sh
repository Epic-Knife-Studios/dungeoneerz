# Dungeoneerz
# Copyright(c) 2015 Samuel "MrOverkill" Meyers

if [ ! -d build ]
then
    echo "Error : build directory missing!"
    return -1
fi

if [ ! -d build/scripts ]
then
    echo "Error : build scripts missing! ( No idea how. )"
    return -1
fi

if [ -a build/obj ]
then
    rm -rf build/obj
fi

mkdir build/obj

if [ -a build/lib ]
then
    rm -rf build/lib
fi

mkdir build/lib
