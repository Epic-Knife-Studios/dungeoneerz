# Dungeoneerz
# Copyright(c) 2015 Samuel "MrOverkill" Meyers

VERSION=0.0.1

GAME_LIBS= -ldungeonlib -shared

CORE_LIBS= -ldungeonlib -ldungeongame

#LIB_LIBS= -Ldependencies/SFML/lib \
#-lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio

DUNGEON_INCLUDE= -Iinclude

LIB_INCLUDE= ${DUNGEON_INCLUDE} -Idependencies/SFML/include

default:
	@echo "Targets :"
	@echo "linux-dev, linux-release"
	@echo "osx-dev, osx-release"

linux-dev:
	@echo "Setting up..."
	@bash build/scripts/linux-precompile.sh
	@echo "[library] Compiling common library..."
	@bash build/scripts/linux-compile.sh src/lib/window.cxx build/obj/lib.window.o library
	@bash build/scripts/linux-compile.sh src/lib/config.cxx build/obj/lib.config.o library
	@bash build/scripts/linux-compile.sh src/lib/logger.cxx build/obj/lib.logger.o library
	@bash build/scripts/linux-link.sh build/obj/lib.\*.o build/lib/libdungeonlib.so library -shared
	@echo "[game] Compiling game..."
	@bash build/scripts/linux-compile.sh src/game/game.cxx build/obj/game.game.o game
	@bash build/scripts/linux-link.sh build/obj/game.\*.o build/lib/libdungeongame.so game "${GAME_LIBS}"
	@echo "[engine] Compiling engine..."
	@bash build/scripts/linux-compile.sh src/core/main.cxx build/obj/engine.main.o engine
	@bash build/scripts/linux-link.sh build/obj/engine.\*.o build/dungeon engine "${CORE_LIBS}"
	@echo "Finishing up..."
	@bash build/scripts/linux-postcompile.sh
	@echo "Done!"

linux-release:
	make linux-dev
	bash build/scripts/linux-package.sh ${VERSION}

osx-dev:
	@echo "Setting up..."
	@bash build/scripts/osx-precompile.sh
	@echo "[library] Compiling common library..."
	@bash build/scripts/osx-compile.sh src/lib/window.cxx build/obj/lib.window.o library
	@bash build/scripts/osx-compile.sh src/lib/config.cxx build/obj/lib.config.o library
	@bash build/scripts/osx-compile.sh src/lib/logger.cxx build/obj/lib.logger.o library
	@bash build/scripts/osx-link.sh build/obj/lib.\*.o build/lib/libdungeonlib.so library -shared
	@echo "[game] Compiling game..."
	@bash build/scripts/osx-compile.sh src/game/game.cxx build/obj/game.game.o game
	@bash build/scripts/osx-link.sh build/obj/game.\*.o build/lib/libdungeongame.so game "${GAME_LIBS}"
	@echo "[engine] Compiling engine..."
	@bash build/scripts/osx-compile.sh src/core/main.cxx build/obj/engine.main.o engine
	@bash build/scripts/osx-link.sh build/obj/engine.\*.o build/dungeon engine "${CORE_LIBS}"
	@echo "Finishing up..."
	@bash build/scripts/osx-postcompile.sh
	@echo "Done!"

osx-release:
	make osx-dev
	bash build/scripts/osx-package.sh ${VERSION}
