# Dungeoneerz
# Copyright(c) 2015 Samuel "MrOverkill" Meyers

VERSION=0.0.1

GAME_LIBS= -ldungeonlib -ldl -shared

CORE_LIBS= -ldungeonlib -ldl

DUNGEON_INCLUDE= -Iinclude

LIB_INCLUDE= ${DUNGEON_INCLUDE}

default:
	@echo "Targets :"
	@echo "linux-dev, linux-release"
	@echo "osx-dev, osx-release"

linux-dev:
	@echo "Setting up..."
	@bash build/scripts/linux-precompile.sh
	@echo "[library] Compiling common library..."
	@bash build/scripts/linux-compile.sh src/lib/config.cxx build/obj/lib.config.o library
	@bash build/scripts/linux-compile.sh src/lib/logger.cxx build/obj/lib.logger.o library
	@bash build/scripts/linux-compile.sh src/lib/util.cxx build/obj/lib.util.o library
	@bash build/scripts/linux-compile.sh src/lib/event.cxx build/obj/lib.event.o library
	@bash build/scripts/linux-compile.sh src/lib/module.cxx build/obj/lib.module.o library
	@bash build/scripts/linux-link.sh build/obj/lib.\*.o build/lib/libdungeonlib.so library -shared
	@echo "[engine] Compiling engine..."
	@bash build/scripts/linux-compile.sh src/engine/main.cxx build/obj/engine.main.o engine
	@bash build/scripts/linux-link.sh build/obj/engine.\*.o build/dungeon.out engine "${CORE_LIBS}"
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
	@bash build/scripts/osx-compile.sh src/lib/config.cxx build/obj/lib.config.o library
	@bash build/scripts/osx-compile.sh src/lib/logger.cxx build/obj/lib.logger.o library
	@bash build/scripts/osx-compile.sh src/lib/util.cxx build/obj/lib.util.o library
	@bash build/scripts/osx-compile.sh src/lib/module.cxx build/obj/lib.module.o library
	@bash build/scripts/osx-compile.sh src/lib/event.cxx build/obj/lib.event.o library
	@bash build/scripts/osx-link.sh build/obj/lib.\*.o build/lib/libdungeonlib.so library -shared
	@bash build/scripts/osx-link.sh build/obj/game.\*.o build/lib/libdungeongame.so game "${GAME_LIBS}"
	@echo "[engine] Compiling engine..."
	@bash build/scripts/osx-compile.sh src/engine/main.cxx build/obj/engine.main.o engine
	@bash build/scripts/osx-link.sh build/obj/engine.\*.o build/dungeon engine "${CORE_LIBS}"
	@echo "Finishing up..."
	@bash build/scripts/osx-postcompile.sh
	@echo "Done!"

osx-release:
	make osx-dev
	bash build/scripts/osx-package.sh ${VERSION}
