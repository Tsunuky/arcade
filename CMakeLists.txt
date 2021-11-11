cmake_minimum_required(VERSION 3.10)
project(OOP)

set(CMAKE_CXX_STANDARD 14)

include_directories(core/include)
include_directories(game/pacman/include)
include_directories(game/nibbler/include)
include_directories(graphic/ncurses/include)
include_directories(graphic/sdl/include)
include_directories(graphic/sfml/include)

add_executable(OOP
        core/include/Core.hpp
        core/include/IGame.hpp
        core/include/IGraphical.hpp
        core/sources/Core.cpp
        core/sources/Main.cpp
        game/pacman/include/Pacman.hpp
        game/pacman/include/IGame.hpp
        game/pacman/sources/Main.cpp
        game/nibbler/include/Nibbler.hpp
        game/nibbler/include/IGame.hpp
        game/nibbler/sources/Main.cpp
        graphic/ncurses/include/Ncurses.hpp
        graphic/ncurses/sources/Main.cpp
        graphic/sdl/include/IGraphical.hpp
        graphic/sdl/include/Sdl.hpp
        graphic/sdl/sources/Main.cpp
        graphic/sfml/include/IGraphical.hpp
        graphic/sfml/include/Sfml.hpp
        graphic/sfml/sources/Main.cpp)
