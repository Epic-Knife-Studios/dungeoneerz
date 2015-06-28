# Dungeoneerz
# Copyright(c) 2015 Samuel "MrOverkill" Meyers

VERSION=0.0.1

GAME_LIBS= -Lbuild/lib \
-ldungeonlib

CORE_LIBS= ${GAME_LIBS} \
-ldungeongame

LIB_LIBS= -Ldependencies/SFML/lib \
-lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio

DUNGEON_INCLUDE= -Iinclude

LIB_INCLUDE= ${DUNGEON_INCLUDE} -Idependencies/SFML/include

LINUX_FLAGS= -c -fPIC -DDOS=LINUX

default:
	# Targets : linux-dev, linux-release

linux-dev:
	@echo "Setting up..."
	@bash build/scripts/linux-precompile.sh
	@echo "[library] Compiling common library..."
	@echo "[library] Compile : lib/window.cxx"
	@g++ ${LINUX_FLAGS} ${LIB_INCLUDE} \
	src/lib/window.cxx -o build/obj/lib.window.o
	@echo "[library] Linking common library..."
	@g++ -shared build/obj/lib.*.o -o build/lib/libdungeonlib.so ${LIB_LIBS}
	@echo "[game] Compiling game..."
	@echo "[game] Compile : game/game.cxx"
	@g++ ${LINUX_FLAGS} ${DUNGEON_INCLUDE} \
	src/game/game.cxx -o build/obj/game.game.o
	@echo "[game] Linking game..."
	@g++ -shared build/obj/game.*.o -o build/lib/libdungeongame.so ${GAME_LIBS}
	@echo "[engine] Compiling engine..."
	@echo "[engine] Compile : core/main.cxx"
	@g++ ${LINUX_FLAGS} ${DUNGEON_INCLUDE} \
	src/core/main.cxx -o build/obj/core.main.o
	@echo "[engine] Linking engine..."
	@g++ build/obj/core.*.o -o build/dungeon.out ${CORE_LIBS}
	@echo "Finishing up..."
	@bash build/scripts/linux-postcompile.sh
	@echo "Done!"

linux-release:
	make linux-dev
	bash build/scripts/linux-package.sh ${VERSION}
