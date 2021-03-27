//
// Created by jeroen on 28/02/2021.
//

#include <cmath>
#include "Base.hpp"

Base::Base(int _base) : base(_base) { }
Base::Base(int _base, int _base2) : base(_base), base2(_base2) { }

std::string Base::toBase(int num, bool indicator) {
    std::string str;
    if(!indicator) {
        do {
            if(num % base > 9) { // for all base compatibility
                str += abc[num % base - 10];
            } else {
                str += std::to_string(num % base);
            }
            num /= (int) base;
        } while (num != 0);
    } else {
        do {
            if(num % base2 > 9) { // for all base compatibility
                str += abc[num % base2 - 10];
            } else {
                str += std::to_string(num % base2);
            }
            num /= (int) base2;
        } while (num != 0);
    }
    std::reverse(str.begin(), str.end());

    return str;
}

int Base::toDec(std::string str) {
    int num{ 0 };
    std::reverse(str.begin(), str.end());
    for(int i{ 0 }; i < str.length(); ++i) {
        num += (int)(abc.find(str[i]) == -1 ? (int)(str[i] - '0' /* To convert char into int... */) * std::pow(base, i) : (int)(abc.find(str[i]) + 10.00) * std::pow(base, i)); // for compatibility to all bases
    }

    return num;
}

std::string Base::baseToBase(std::string str) {
    return toBase(toDec(str), true);
}

