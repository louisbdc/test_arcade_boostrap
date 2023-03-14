/*
** EPITECH PROJECT, 2023
** lib1.cpp
** File description:
** Created by louis on 13/03/23.
*/

#include <iostream>

extern "C"
{
    void __attribute__((constructor)) init_mylibrary() {
        std::cout << "[libfoo] : Initialisation\n";
    }
    void __attribute__((destructor)) cleanup_mylibrary() {
        std::cout << "[libfoo] : Finalisation\n";
    }
    int entryPoint() {
        std::cout << "[libfoo] : Entrée\n";
        return 0;
    }
}
