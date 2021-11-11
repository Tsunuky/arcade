/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pacman.hpp
*/

#ifndef OOP_PACMAN_HPP
#define OOP_PACMAN_HPP

#include <iostream>
#include "IGame.hpp"

class Pacman : public IGame {
public:
    Pacman() : key(NONE), score(0)
    {};
    int InitGame() override
    {return 0;};
    int Action() override
    {
        switch (key) {
            case UP:
                std::cout << "Pacman : UP" << std::endl;
                break;
            case DOWN:
                std::cout << "Pacman : DOWN" << std::endl;
                break;
            case LEFT:
                std::cout << "Pacman : LEFT" << std::endl;
                break;
            case RIGHT:
                std::cout << "Pacman : RIGHT" << std::endl;
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
    return new(Pacman);
}
}

#endif //OOP_PACMAN_HPP
