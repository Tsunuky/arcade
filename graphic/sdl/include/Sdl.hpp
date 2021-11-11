/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sdl.hpp
*/

#ifndef LIB_3_HPP_
#define LIB_3_HPP_

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "IGraphical.hpp"

class Sdl : public IGraphical {
public:

    Sdl() : Sdl("SDL")
    {};
    explicit Sdl(const std::string &name) : _name(name)
    {};
    void createWindow() override
    {
        SDL_Init(SDL_INIT_VIDEO);
        TTF_Init();
        _window = SDL_CreateWindow(_name.c_str(), SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
        render = SDL_CreateRenderer(_window, -1, 0);
        SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
        SDL_RenderClear(render);
        Font = TTF_OpenFont("./assets/OpenSans-Regular.ttf", 24);
        White = {255, 255, 255};
        setsize(&obj.first.rect, 0, 0, 100, 100);
        createTexture();
    };

    void destroyWindow() override
    {
        TTF_CloseFont(Font);
        TTF_Quit();
        SDL_DestroyRenderer(render);
        SDL_Quit();
    };

    void createObj(Object_t object) override
    {
        int w;
        int h;

        if (object.type == TEXT) {
            obj.first.surf = TTF_RenderText_Solid(Font, object.text.c_str(),
                White);
            obj.first.text = SDL_CreateTextureFromSurface(render,
                obj.first.surf);
            SDL_QueryTexture(obj.first.text, NULL, NULL, &w, &h);
            setsize(&obj.first.rect, static_cast<int>(object.pos.x),
                static_cast<int>(object.pos.y), w, h);
            obj.second = object.num;
            objs.push_back(obj);
        }
    };
    void draw() override
    {
        SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
        SDL_RenderClear(render);
        updateTexture();
        SDL_RenderPresent(render);
        SDL_PumpEvents();
    };

    void clearObj() override
    {};

    void setPosition(int id, Pos pos) override
    {
        std::transform(objs.begin(), objs.end(), objs.begin(),
            [id, pos, this](std::pair<Obj, int> p) {
                if (p.second == id)
                    setsize(&p.first.rect, static_cast<int>(pos.x),
                        static_cast<int>(pos.y), p.first.rect.w,
                        p.first.rect.h);
                return p;
            });
    };
    ARCADE getInput() override
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            return ARCADE::QUIT;
        if (event.type == SDL_KEYDOWN) {
            SDL_Delay(200);
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    return ARCADE::UP;
                case SDLK_DOWN:
                    return ARCADE::DOWN;
                case SDLK_LEFT:
                    return ARCADE::LEFT;
                case SDLK_RIGHT:
                    return ARCADE::RIGHT;
                case SDLK_ESCAPE:
                    return ARCADE::QUIT;
                case SDLK_j:
                    return ARCADE::PREV_GRAPH_LIB;
                case SDLK_k:
                    return ARCADE::NEXT_GRAPH_LIB;
                case SDLK_l:
                    return ARCADE::PREV_GAME_LIB;
                case SDLK_m:
                    return ARCADE::PREV_GAME_LIB;
                case SDLK_SPACE:
                    return ARCADE::SPACE;
                case SDLK_BACKSPACE:
                    return ARCADE::RETURN;
                case SDLK_RETURN:
                    return ARCADE::ENTER;
                default:
                    return ARCADE::NONE;
            }
        }
        return ARCADE::NONE;
    };
    void EraseObj(int id) override
    {
        if (objs.empty())
            return;
        objs.erase(std::remove_if(objs.begin(), objs.end(),
            [id](std::pair<Obj, int> o) {
                return o.second == id;
            }));
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

public:
    void createTexture();
    void updateTexture();
    void setsize(SDL_Rect *rect, int X, int Y, int W, int H);

private:
    struct Obj {
        SDL_Rect rect;
        SDL_Surface *surf;
        SDL_Texture *text;
    };

private:
    std::string _name;
    SDL_Window *_window{};
    SDL_Event event{};
    SDL_Renderer *render{};
    SDL_Texture *Player{};
    SDL_Rect sizeP{};
    SDL_Rect srcP{};
    SDL_Rect rectM{};
    TTF_Font *Font{};
    SDL_Color White{};
    SDL_Texture *Message{};

    std::pair<Obj, int> obj{};
    std::vector<std::pair<Obj, int>> objs{};
};

extern "C"
{
IGraphical *getGraphical()
{
    return new(Sdl);
} ;
}

#endif /* !LIB_3_HPP_ */
