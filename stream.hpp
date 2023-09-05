#ifndef STREAM_H
#define STREAM_H

#include <iostream>
#include <bitset>
#include <vector>

std::ostream& operator << (std::ostream& mout, std::bitset<8UL>);
std::ostream& operator << (std::ostream& mout, std::vector<bool>);

std::ostream& operator<< (std::ostream& mcout, std::vector<int32_t> cont);

#endif