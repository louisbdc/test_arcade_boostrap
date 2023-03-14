/*
** EPITECH PROJECT, 2023
** lib2.cpp
** File description:
** Created by louis on 13/03/23.
*/

#include <iostream>

extern "C"
{
    void __attribute__((constructor)) init_mylibrary() {
        std::cout << "[libbar] : Initialisation\n";
    }
    void __attribute__((destructor)) cleanup_mylibrary() {
        std::cout << "[libbar] : Finalisation\n";
    }
    int entryPoint() {
        std::cout << "[libbar] : Entrée\n";
        return 0;
    }
}