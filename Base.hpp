//
// Created by jeroen on 28/02/2021.
//

#ifndef BASE_CALCULATOR_BASE_HPP
#define BASE_CALCULATOR_BASE_HPP

#include <iostream>

class Base {
public:
    Base(int);
    Base(int, int);

    std::string toBase(int, bool);
    int toDec(std::string);
    std::string baseToBase(std::string);

private:
    unsigned base, base2;
    std::string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};


#endif //BASE_CALCULATOR_BASE_HPP
