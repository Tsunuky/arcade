/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Core.cpp
*/

#include "Core.hpp"

void Core::getLibs(const std::string &path, std::vector<std::string> &lib)
{
    DIR *dir = opendir(path.c_str());
    if (dir == nullptr)
        throw ArcadeError(path + " is not a valid path.");
    dirent *dp;
    std::string file;
    while ((dp = readdir(dir)) != nullptr) {
        file = dp->d_name;
        if (file.length() < 3)
            continue;
        else if (file.compare(file.length() - 3, 3, ".so") == 0)
            lib.push_back(file);
        else
            continue;
    }
    closedir(dir);
}

int Core::menu(IGraphical *lib, DLLoader<IGame> &loader, int score)
{
    _games.clear();
    _graphicals.clear();
    _gameLibs.clear();
    _graphLibs.clear();
    getLibs("./games", _games);
    getLibs("./libs", _graphicals);
    ARCADE key = NONE;

    Object_t object;

    object.type = TEXT;

    float step = 20;
    float y = step;
    Pos gamePos = {50, y};
    Pos graphPos = {50, y + 100};
    Pos gameBack = gamePos;
    Pos graphBack = graphPos;

    int id = 0;

    for (auto &i : _games) {
        object.text = i;
        object.pos = gamePos;
        object.num = id;
        _gameLibs.push_back(object);
        gamePos.y += step;
        id += 1;
    }

    for (auto &i : _graphicals) {
        object.text = i;
        object.pos = graphPos;
        object.num = id;
        _graphLibs.push_back(object);
        graphPos.y += step;
        id += 1;
    }

    object.text = std::string("Score : ") + std::to_string(score);
    object.pos.x = 400;
    object.pos.y = 300;
    object.num = id;
    lib->createObj(object);

    id += 1;

    gamePos = gameBack;
    gamePos.x -= 20;
    graphPos = graphBack;
    graphPos.x -= 20;
    object.text = ">";

    object.num = id;
    object.pos = gamePos;
    _gameLibs.push_back(object);
    id += 1;
    object.num = id;
    object.pos = graphPos;
    _graphLibs.push_back(object);

    for (auto &i : _gameLibs)
        lib->createObj(i);
    for (auto &i : _graphLibs)
        lib->createObj(i);

    Pos pos = {};

    while (true) {
        key = lib->getInput();
        if (key == QUIT)
            return 1;
        if (key == NEXT_GAME_LIB)
            gameIndex >= _games.size() - 1 ? (gameIndex = 0) : (gameIndex += 1);
        if (key == PREV_GAME_LIB)
            gameIndex == 0 ? (gameIndex = _games.size() - 1)
                : (gameIndex -= 1);
        if (key == NEXT_GRAPH_LIB)
            graphIndex >= _graphicals.size() - 1 ? (graphIndex = 0) :
                (graphIndex += 1);
        if (key == PREV_GRAPH_LIB)
            graphIndex == 0 ? (graphIndex = _graphicals.size() - 1)
                : (graphIndex -= 1);
        if (key == ENTER)
            break;
        pos.x = gamePos.x;
        pos.y = gamePos.y + gameIndex * step;
        lib->setPosition(id - 1, pos);
        pos.x = graphPos.x;
        pos.y = graphPos.y + graphIndex * step;
        lib->setPosition(id, pos);
        lib->draw();
    }
    loader.openLibrary("./games/" + _games.at(gameIndex), 1);

    while (id >= 0) {
        lib->EraseObj(id);
        id -= 1;
    }
    return 0;
}