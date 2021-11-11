/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGame.hpp
*/

#ifndef OOP_IGAME_HPP
#define OOP_IGAME_HPP

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

class IGame {
protected:
public:
    virtual ~IGame() = default;
    virtual int InitGame() = 0;
    virtual int Action() = 0;
    virtual Object_t getObjectByNumber(uint num) = 0;
    virtual uint getNum() = 0;
    virtual void getInput(ARCADE) = 0;
};

#endif //OOP_IGAME_HPP
