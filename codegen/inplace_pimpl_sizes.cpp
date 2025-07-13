#include <iostream>
#include <string>
#include <vector>
#include <thread>

namespace {
    template<typename T>
    void printType(const char* name)
    {
        std::cout << "constexpr SizeT " << name << "Size = " << sizeof(T) << ";\n"; 
        std::cout << "constexpr SizeT " << name << "Alignment = " << alignof(T) << ";\n"; 
    }
}

int main() {
    std::cout << R"(
#pragma once
#include "SFML/Base/SizeT.hpp"
namespace sf::base {
    )";
    printType<std::string>("stdString");
    printType<std::thread>("stdThread");
    static_assert(sizeof(std::vector<int>) == sizeof(std::vector<std::string>));
    static_assert(alignof(std::vector<int>) == alignof(std::vector<std::string>));

    printType<std::vector<int>>("stdVector");

    std::cout << "\n}";
}
