#include "stream.hpp"

#include <iostream>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <functional>

std::ostream& operator << (std::ostream& mout, std::bitset<8UL> bt) {
    for (size_t i = 0; i < 8; i++) {
        std::cout << std::boolalpha << std::setw(5) << std::setfill('-') << std::right << bt.test(i) << " ";
    }

    return mout;
}

std::ostream& operator << (std::ostream& mout, std::vector<bool> _vec) {
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << std::boolalpha << std::setw(5) << std::setfill(' ') << std::right << _vec.at(i) << " ";
    }

    return mout;
}

std::ostream& operator<< (std::ostream& mcout, std::vector<int32_t> cont) {
    std::for_each(cont.begin(), cont.end(), [](int32_t a) -> void {
        std::cout << a << " ";
        });
    return mcout;
}