cmake_minimum_required(VERSION 3.1)

project(Dungeoneerz)

include_directories(include)

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

add_library(dungeonlib SHARED ${EngineSrc})

target_link_libraries(dungeonlib)

add_library(dungeongame SHARED ${GameSrc})

target_link_libraries(dungeongame dungeonlib)

add_executable(dungeon ${BinSrc})

target_link_libraries(dungeon dungeonlib dungeongame)
