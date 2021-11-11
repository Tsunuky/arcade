/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ncurses.hpp
*/

#ifndef ARCADE_TEST_LIB_1_HPP
#define ARCADE_TEST_LIB_1_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include "curses.h"
#include "IGraphical.hpp"

class Curse : public IGraphical {
public:
    Curse() : Curse("ncurses")
    {
        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        curs_set(0);
        int h = 3;
        int w = 10;
        int y = (LINES - h) / 2;
        int x = (COLS - w) / 2;
        win = newwin(w, h, y, x);
        timeout(50);
    };
    explicit Curse(const std::string &name) : _name(name), win(nullptr)
    {};
    void createWindow() override
    {};

    void destroyWindow() override
    {
        endwin();
    };

    void createObj(Object_t object) override
    {
        if (object.type == TEXT) {
            obj.first.x = static_cast<int>(object.pos.x / 20);
            obj.first.y = static_cast<int>(object.pos.y / 10);
            obj.first.text = object.text;
            obj.second = object.num;
            objs.push_back(obj);
        }
    };

    void draw() override
    {
        clear();
        for (auto &o : objs) {
            mvprintw(o.first.y, o.first.x, o.first.text.c_str());
        }
    };

    void clearObj() override
    {};

    void setPosition(int id, Pos pos) override
    {
        std::transform(objs.begin(), objs.end(), objs.begin(),
            [id, pos](std::pair<Obj, int> p) {
                if (p.second == id) {
                    p.first.x = static_cast<int>(pos.x / 20);
                    p.first.y = static_cast<int>(pos.y / 10);
                }
                return p;

            });
    };
    ARCADE getInput() override
    {
        int ch = getch();
        refresh();
        switch (ch) {
            case 27:
                return ARCADE::QUIT;
            case KEY_UP:
                return ARCADE::UP;
            case KEY_DOWN:
                return ARCADE::DOWN;
            case KEY_LEFT:
                return ARCADE::LEFT;
            case KEY_RIGHT:
                return ARCADE::RIGHT;
            case 'j':
                return ARCADE::PREV_GRAPH_LIB;
            case 'k':
                return ARCADE::NEXT_GRAPH_LIB;
            case 'l':
                return ARCADE::PREV_GAME_LIB;
            case 'm':
                return ARCADE::NEXT_GAME_LIB;
            case ' ':
                return ARCADE::SPACE;
            case KEY_BACKSPACE:
                return ARCADE::RETURN;
            case 10:
                return ARCADE::ENTER;
            default:
                break;
        }
        return ARCADE::NONE;
    };
    void EraseObj(int num) override
    {
        if (objs.empty())
            return;
        objs.erase(std::remove_if(objs.begin(), objs.end(), [num]
            (std::pair<Obj, int> o) {
            return o.second == num;
        }), objs.end());
    };
    void HideObj(int num) override
    {};
    void showObj(int num) override
    {};

    void updateObj(int, uint) override
    {};

    uint getNum() override
    {
        return 0;
    };

private:
    struct Obj {
        std::string text;
        int y = 0;
        int x = 0;
    };

private:
    std::string _name;
    WINDOW *win;
    std::pair<Obj, int> obj;
    std::vector<std::pair<Obj, int>> objs;

};

extern "C"
{
IGraphical *getGraphical()
{return new (Curse);} ;
}

#endif //ARCADE_TEST_LIB_1_HPP
