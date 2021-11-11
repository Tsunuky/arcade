/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ArcadeError.hpp
*/

#ifndef OOP_ARCADEERROR_HPP
#define OOP_ARCADEERROR_HPP

#include <exception>
#include <string>

class ArcadeError : public std::exception {
public:
    explicit ArcadeError(const std::string &msg) : _msg(msg) {};
    const char *what() {return _msg.c_str();};

private:
    std::string _msg;
};

#endif //OOP_ARCADEERROR_HPP
