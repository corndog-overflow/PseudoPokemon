cmake_minimum_required(VERSION 3.23)
project(pa3_corndog_overflow)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(pa3_corndog_overflow
        GameObject.cpp
        GameObject.h
        Point2D.cpp
        Point2D.h
        Vector2D.cpp
        Vector2D.h
        PokemonCenter.cpp
        PokemonCenter.h
        PokemonGym.cpp
        PokemonGym.h
        Building.cpp
        Building.h
        GameCommand.h
        GameCommand.cpp
        Model.h
        Model.cpp
        View.cpp
        View.h
        Trainer.h
        Trainer.cpp
        main.cpp
        WildPokemon.h WildPokemon.cpp)
