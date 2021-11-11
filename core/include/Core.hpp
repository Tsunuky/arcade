/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Core.hpp
*/

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include <string>
#include <dlfcn.h>
#include <iostream>
#include <vector>

#include <sys/types.h>
#include <dirent.h>

#include "IGraphical.hpp"
#include "IGame.hpp"
#include "ArcadeError.hpp"

template <typename T>
class DLLoader {
public:
    DLLoader() : handle(nullptr), function(nullptr), obj(nullptr)
    {};;
    explicit DLLoader(const std::string &path) : handle(nullptr),
        function(nullptr)
    {
        openLibrary(path, 0);
    };

    ~DLLoader()
    {
        if (handle != nullptr)
            dlclose(handle);
    };

    void openLibrary(const std::string &path, int type)
    {
        handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!handle)
            throw ArcadeError(dlerror());

        if (type == 0 && !(function = dlsym(handle, "getGraphical")))
            throw ArcadeError(dlerror());
        if (type == 1 && !(function = dlsym(handle, "getGame")))
            throw ArcadeError(dlerror());
    };

    T *getLibrary()
    {
        obj = ((T *(*)()) function)();

        return obj;
    };

    void deleteLib()
    {
        if (obj != nullptr)
            delete(obj);
    }

private:
    void *handle;
    void *function;
    std::vector<std::string> _graphicals;
    std::vector<std::string> _games;

    T *obj;

};

class Core {
public:
    Core() : graphIndex(0), gameIndex(0)
    {};
    int menu(IGraphical *lib, DLLoader<IGame> &loader, int score);
private:
    void getLibs(const std::string &path, std::vector<std::string> &lib);
    std::vector<std::string> _graphicals;
    std::vector<std::string> _games;
    std::vector<Object_t> _graphLibs;
    std::vector<Object_t> _gameLibs;
    unsigned long graphIndex;
    unsigned long gameIndex;
};

#endif //ARCADE_CORE_HPP