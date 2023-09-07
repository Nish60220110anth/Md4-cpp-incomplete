#include "util.hpp"

#include <iostream>
#include <cassert>
#include <iomanip>

std::vector<bool> vec_from_bitset8s(std::bitset<8UL> bt) {
    std::vector<bool> r;

    for (size_t s = 0; s < 8; s++) {
        r.push_back(bt.test(s));
    }

    return r;
}

std::bitset<8UL> bitset8s_from_vec(std::vector<bool> vec) {
    std::bitset<8UL> bt;
    bt.reset();

    assert(vec.size() == 8);

    for (int i = 0;i < 8;i++) {
        if (vec[i]) {
            bt.set(i, true);
        }
    }

    return bt;
}


std::bitset<8UL> reverse_bitset_8s(std::bitset<8UL> bt) {
    std::string s = bt.to_string();
    std::reverse(s.begin(), s.end());
    return std::bitset<8UL>(s);
}

std::bitset<8UL> bitset8s_from_uchar(unsigned char a) {
    return std::bitset<8UL>(a);
}

std::vector<bool> vec_from_size_t(size_t t) {
    std::bitset<64UL> bt(t);
    std::vector<bool> vec;

    for (int i = 0;i < 64;i++) {
        vec.push_back(bt.test(i));
    }

    return vec;
}

std::string string_from_bitset(std::bitset<32UL> bt) {
    std::string res;

    for (int i = 0;i < 32;i += 4) {
        int8_t a1 = bt.test(i), a2 = bt.test(i + 1), a3 = bt.test(i + 2), a4 = bt.test(i + 3);
        a4 = 2 * a4 + a3;
        a4 = 2 * a4 + a2;
        a4 = 2 * a4 + a1;


        if (a4 <= 9) a4 = 48 + a4;
        else a4 = 87 + a4;

        unsigned c = static_cast<unsigned char>(a4);
        res.push_back(c);
    }

    return res;
}

int32_t F(int32_t x, int32_t y, int32_t z) {
    return (x & y) | ((~x) & z);
}

int32_t G(int32_t x, int32_t y, int32_t z) {
    return (x & y) | (y & z) | (z & x);
}

int32_t H(int32_t x, int32_t y, int32_t z) {
    return x ^ y ^ z;
}

int32_t int32_t_from_bitset(std::bitset<32UL> bt) {
    int32_t r = 0;
    for (int i = 0;i < 32;i++) {
        r = 2 * r + bt.test(i);
    }

    return r;
}

std::bitset<32UL> bitset_from_int32_t(int32_t a) {
    std::bitset<32UL> f;
    f.reset();

    for (int i = 0;i < 32;i++) {
        if (((a >> i) & 1) != 0) {
            f.set(i, true);
        }
    }

    return f;
}

std::bitset<32UL> left_rotate(std::bitset<32UL> num, int pl) {
    if (pl == 0) return num;
    else if (pl > 0) return (num << pl) | (num >> (32 - pl));
    else return right_rotate(num, -pl);
}

std::bitset<32UL> right_rotate(std::bitset<32UL> num, int pl) {
    if (pl == 0) return num;
    else if (pl > 0) return (num >> pl) | (num << (32 - pl));
    else return left_rotate(num, -pl);
}

std::bitset<32UL> reverse_bitset_32s(std::bitset<32UL> bt) {
    std::bitset<32UL> f = bt;

    for (int i = 0;i < 16;i++) {
        bool f1 = f.test(i), f2 = f.test(31 - i);
        f.set(31 - i, f1);
        f.set(i, f2);
    }

    return f;
}

std::bitset<32UL> add(std::bitset<32UL> bt1, std::bitset<32UL> bt2) {
    int32_t a1 = int32_t_from_bitset(reverse_bitset_32s(bt1)), a2 = int32_t_from_bitset(reverse_bitset_32s(bt2));
    return reverse_bitset_32s(bitset_from_int32_t(a1 + a2));
}

std::bitset<32UL> add(std::bitset<32UL> bt, int32_t a) {
    // std::cout << std::hex << "original" << a << "\n";
    std::bitset<32UL> bt1 = bitset_from_int32_t(a);
    // std::cout << std::hex << int32_t_from_bitset(reverse_bitset_32s(bt1)) << "\n";
    return add(bt, bt1);
}