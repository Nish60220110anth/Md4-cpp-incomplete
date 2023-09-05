#ifndef UTIL_H
#define UTIL_H

#include <algorithm>
#include <vector>
#include <bitset>


std::bitset<8UL> bitset8s_from_vec(std::vector<bool>);
std::vector<bool> vec_from_bitset8s(std::bitset<8UL>);

std::bitset<8UL> reverse_bitset_8s(std::bitset<8UL>);
std::bitset<32UL> reverse_bitset_32s(std::bitset<32UL>);

/**
 * convert unsigned char to bitstream
 *
 * \param a
 * unsigned char
 *
 * \returns
 * returns the bitstream of the unsigned char using inbuilt constructor
 *
 * \note
 * you can statically typecast the signed char to unsigned char , becoz the data we are dealing
 * with is within the allowed range
*/
std::bitset<8UL> bitset8s_from_uchar(unsigned char);

std::vector<bool> vec_from_size_t(size_t);
std::string string_from_bitset(std::bitset<32UL>);
int32_t int32_t_from_bitset(std::bitset<32UL>);
std::bitset<32UL> bitset_from_int32_t(int32_t);

int32_t F(int32_t x, int32_t y, int32_t z);
int32_t G(int32_t x, int32_t y, int32_t z);
int32_t H(int32_t x, int32_t y, int32_t z);
std::bitset<32UL> left_rotate(std::bitset<32UL> num, int pl);
std::bitset<32UL> right_rotate(std::bitset<32UL> num, int pl);
std::bitset<32UL> add(std::bitset<32UL>,std::bitset<32UL>);
std::bitset<32UL> add(std::bitset<32UL>,int32_t);

#endif