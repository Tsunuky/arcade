/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SolarFox.hpp
*/

#ifndef OOP_GAME_2_HPP
#define OOP_GAME_2_HPP

#include <iostream>
#include "IGame.hpp"

class SolarFox : public IGame {
public:
    SolarFox() : key(NONE), score(0)
    {};

    int InitGame() override
    {
        return 0;
    };

    int Action() override
    {
        switch (key) {
            case UP:
                std::cout << "SolarFox : UP" << std::endl;
                break;
            case DOWN:
                std::cout << "SolarFox : DOWN" << std::endl;
                break;
            case LEFT:
                std::cout << "SolarFox : LEFT" << std::endl;
                break;
            case RIGHT:
                std::cout << "SolarFox : RIGHT" << std::endl;
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
    return new(SolarFox);
}
}

#endif //OOP_GAME_1_HPP

