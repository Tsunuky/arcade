/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include "Sdl.hpp"

void Sdl::createTexture()
{
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
}

void Sdl::updateTexture()
{
    for (auto &obj : objs)
        SDL_RenderCopy(render, obj.first.text, nullptr, &obj.first.rect);
}

void Sdl::setsize(SDL_Rect *rect, int X, int Y, int W, int H)
{
    rect->x = X;
    rect->y = Y;
    rect->w = W;
    rect->h = H;
}