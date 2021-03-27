//
// Created by jeroen on 28/02/2021.
//

#include <iostream>
#include "Base.hpp"

int main() {
loop:
    try {
        int decision, number, base_x, base_y;
        std::string num;
        std::cout << "(0) Convert a decimal number to base(x)\n(1) Convert a number of base(x) to decimal\n(2) Convert a number of base(x) to a number of base(y)\nYour decision: ";
        std::cin >> decision;
        if(decision != 0 && decision != 1 && decision != 2) {
            throw 012;
        }
        if(decision == 0) { // toBase
            std::cout << "Decimal number: ";
            std::cin >> number;
            if(number < 0) {
                throw -0;
            }
            std::cout << "Base x: ";
            std::cin >> base_x;
            if(base_x < 2 || base_x > 36) {
                throw 236;
            }
            Base obj{base_x};
            std::cout << obj.toBase(number, false);
        } else { // baseToBase
            std::cout << "Base x: ";
            std::cin >> base_x;
            if(base_x < 2 || base_x > 36) {
                throw 236;
            }
            std::cout << "Number: ";
            std::cin >> num;
            if(decision == 2) {
                std::cout << "Base y: ";
                std::cin >> base_y;
                Base obj{base_x, base_y};
                std::cout << obj.baseToBase(num);
            } else {
                Base obj{base_x};
                std::cout << obj.toDec(num);
            }
        }
    }
    catch (int x) {
        switch(x) {
            case -0:
                std::cout << "\n\nA problem occurred - the number can't go beneath 0, please try again...";
                goto loop;

            case 236:
                std::cout << "\n\nA problem occurred - the base must be in the range of 2-36, please try again...";
                goto loop;

            case 012:
                std::cout << "\n\nA problem occurred - incorrect input, please try again...";
                goto loop;

            default:
                std::cout << "\n\nA problem occurred - Error Code: " << x;
        }
    }
    catch(...) {
        std::cout << "\n\nA problem occurred, please try again...";
        goto loop;
    }

    getchar();
    return 0;
}