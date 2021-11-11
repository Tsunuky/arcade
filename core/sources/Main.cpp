/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Main.cpp
*/

#include <iostream>
#include "Core.hpp"
#include "IGraphical.hpp"
#include "IGame.hpp"

int arcade(Core &core, const char *arg)
{
    int score = 0;
    ARCADE key = NONE;

    DLLoader<IGraphical> graphicalLoader(arg);
    DLLoader<IGame> gameLoader = DLLoader<IGame>();

    IGraphical *graphical = graphicalLoader.getLibrary();
    IGame *game = nullptr;

    graphical->createWindow();

    if (core.menu(graphical, gameLoader, score)) {
        graphical->destroyWindow();
        graphicalLoader.deleteLib();
        return 0;
    }

    game = gameLoader.getLibrary();

    game->InitGame();
    while (key != QUIT) {
        key = graphical->getInput();
        game->getInput(key);
        score = game->Action();
        if (score != -1) {
            if (core.menu(graphical, gameLoader, score))
                key = QUIT;
            else
                game = gameLoader.getLibrary();
        }
        graphical->draw();
    }
    graphical->destroyWindow();
    graphicalLoader.deleteLib();
    gameLoader.deleteLib();
    return 0;
}

int main(int ac, char **av)
{
    Core core;
    int result = 0;

    if (ac != 2) {
        std::cerr << "Usage: ./" << av[0] << " path/to/graphical/library" <<
            std::endl;
        return 84;
    }

    try {
        result = arcade(core, av[1]);
    } catch (ArcadeError &e) {
        std::cerr << e.what() << std::endl;
        result = 84;
    }
    return result;
}