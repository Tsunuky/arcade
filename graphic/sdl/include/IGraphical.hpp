/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Igraphical.hpp
*/

#ifndef IGRAPHICAL_HPP
#define IGRAPHICAL_HPP

#include "ArcadeError.hpp"
#include <string>

#ifndef ARCADE_COMMON
#define ARCADE_COMMON

enum TYPE {
    RECTANGLE,
    SPRITE,
    TEXT
};

enum ARCADE {
    QUIT = -1,
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    RETURN,
    ENTER,
    SPACE,
    PREV_GRAPH_LIB,
    NEXT_GRAPH_LIB,
    PREV_GAME_LIB,
    NEXT_GAME_LIB,
};

struct Pos {
    float x;
    float y;
    float w;
    float h;
};

struct Object_t
{
    TYPE type;
    int num;
    Pos pos;
    Pos size;
    uint spriteType;
    std::string text;
    bool detection;
    void *window;
};

#endif // ARCADE_COMMON

class IGraphical {
public:
    virtual ~IGraphical() = default;
    virtual void createWindow() = 0;
    virtual void createObj(Object_t info) = 0;
    virtual void draw() = 0;
    virtual void setPosition(int, Pos) = 0;
    virtual ARCADE getInput() = 0;
    virtual void updateObj(int, uint) = 0;
    virtual void EraseObj(int num) = 0;
    virtual void HideObj(int num) = 0;
    virtual void showObj(int num) = 0;
    virtual uint getNum() = 0;
    virtual void clearObj() = 0;
    virtual void destroyWindow() = 0;
};

#endif // IGRAPHICAL_HPP
