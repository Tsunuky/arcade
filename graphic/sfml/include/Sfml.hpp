/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml.hpp
*/

#ifndef ARCADE_SFML_HPP
#define ARCADE_SFML_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "IGraphical.hpp"

class Sfml : public IGraphical {
public:
    Sfml() : Sfml("SFML")
    {};

    explicit Sfml(const std::string &name) : _name(name)
    {
        if (!font.loadFromFile("./assets/texgyreheros-regular.otf"))
            throw ArcadeError("Cannot loaf font file.");
        obj.first.setFont(font);
        obj.first.setCharacterSize(10);
        obj.first.setFillColor(sf::Color::White);
    };

    void createWindow() override
    {
        _window.create(sf::VideoMode(800, 600), _name);
    };

    void destroyWindow() override
    {
        _window.close();
    };

    void createObj(Object_t object) override
    {
        if (object.type == TEXT) {
            obj.first.setPosition(object.pos.x, object.pos.y);
            obj.first.setString(object.text);
            obj.second = object.num;
            objs.push_back(obj);
        }
    };

    void draw() override
    {
        _window.clear();
        for (auto &o : objs)
            _window.draw(o.first);
        _window.display();
    };

    void clearObj() override
    {};

    void setPosition(int id, Pos pos) override
    {
        std::transform(objs.begin(), objs.end(), objs.begin(),
            [id, pos](std::pair<sf::Text, int> p) {
                if (p.second == id)
                    p.first.setPosition(pos.x, pos.y);
                return p;

            });
    };

    ARCADE getInput() override
    {
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                return ARCADE::QUIT;

            if (_event.type == sf::Event::KeyPressed) {
                switch (_event.key.code) {
                    case sf::Keyboard::Up:
                        return ARCADE::UP;
                    case sf::Keyboard::Down:
                        return ARCADE::DOWN;
                    case sf::Keyboard::Left:
                        return ARCADE::LEFT;
                    case sf::Keyboard::Right:
                        return ARCADE::RIGHT;
                    case sf::Keyboard::Escape:
                        return ARCADE::QUIT;
                    case sf::Keyboard::J:
                        return ARCADE::PREV_GRAPH_LIB;
                    case sf::Keyboard::K:
                        return ARCADE::NEXT_GRAPH_LIB;
                    case sf::Keyboard::L:
                        return ARCADE::PREV_GAME_LIB;
                    case sf::Keyboard::M:
                        return ARCADE::NEXT_GAME_LIB;
                    case sf::Keyboard::Space:
                        return ARCADE::SPACE;
                    case sf::Keyboard::BackSpace:
                        return ARCADE::RETURN;
                    case sf::Keyboard::Return:
                        return ARCADE::ENTER;
                    default:
                        return ARCADE::NONE;
                }
            }
        }
        return ARCADE::NONE;
    };

    void EraseObj(int num) override
    {
        if (objs.empty())
            return;
        objs.erase(std::remove_if(objs.begin(), objs.end(), [num]
            (std::pair<sf::Text, int> o) {
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
    sf::Font font;
    sf::Text text{};
    std::pair<sf::Text, int> obj;
    std::vector<std::pair<sf::Text, int>> objs;
    std::string _name;
    sf::RenderWindow _window;
    sf::Event _event{};
};

extern "C" {
IGraphical *getGraphical()
{return new(Sfml);} ;
}

#endif //ARCADE_SFML_HPP
