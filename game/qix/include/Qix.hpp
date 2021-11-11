/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Qix.hpp
*/

#ifndef OOP_GAME_2_HPP
#define OOP_GAME_2_HPP

#include <iostream>
#include "IGame.hpp"

class Qix : public IGame {
public:
    Qix() : key(NONE), score(0)
    {};

    int InitGame() override
    {
        return 0;
    };

    int Action() override
    {
        switch (key) {
            case UP:
                std::cout << "Qix : UP" << std::endl;
                break;
            case DOWN:
                std::cout << "Qix : DOWN" << std::endl;
                break;
            case LEFT:
                std::cout << "Qix : LEFT" << std::endl;
                break;
            case RIGHT:
                std::cout << "Qix : RIGHT" << std::endl;
                break;
            case SPACE:
                score = 0;
                break;
            case ENTER:
                score += 10;
                break;
            case RETURN:
                return score;
            default:
                break;
        }
        return -1;
    };

    Object_t getObjectByNumber(uint num) override
    {
        Object_t obj = {};

        return obj;
    };

    uint getNum() override
    {
        return 0;
    };

    void getInput(ARCADE n) override
    {key = n;};

private:
    ARCADE key;
    int score;
};

extern "C" {
IGame *getGame()
{
    return new(Qix);
}
}

#endif //OOP_GAME_1_HPP
