cmake_minimum_required(VERSION 3.1)

project(Dungeoneerz)

set(DUNGEON_VERSION 1)
set(DUNGEON_REVISION 1)

configure_file (
  "include/dungeoneerz/config.h.in"
  "${PROJECT_BINARY_DIR}/include/dungeoneerz/config.h"
  )

include_directories(include)
include_directories("${PROJECT_BINARY_DIR}/include")

file(GLOB EngineSrc
    "src/lib/*.cxx"
    "src/engine/*.cxx"
)

file(GLOB GameSrc
    "src/game/*.cxx"
)

file(GLOB BinSrc
    "src/main.cxx"
)

file(GLOB ModSrc
    "src/mods/graphics/*.cxx"
)

add_library(dungeonlib SHARED ${EngineSrc})

target_link_libraries(dungeonlib)

add_library(dungeongame SHARED ${GameSrc})

target_link_libraries(dungeongame dungeonlib)

add_executable(dungeon ${BinSrc})

target_link_libraries(dungeon dungeonlib dungeongame)

add_library(graphicsmod SHARED ${ModSrc})

target_link_libraries(graphicsmod dungeonlib dungeongame)
