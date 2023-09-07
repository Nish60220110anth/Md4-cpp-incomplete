#include <iostream>
#include <string>
#include <random>
#include <cstdio>
#include <functional>
#include <filesystem>
#include <cassert>
#include <bitset>
#include <bit>

#include "rand.hpp"
#include "stream.hpp"
#include "util.hpp"

// #define TEST_IMODE
// #define DEV_MODE

void redirectIO() {

#ifndef TEST_IMODE
    freopen64("./input.in", "r", stdin);
#else 
    freopen64("./test.out", "r", stdin);
#endif

    freopen64("./output.out", "w+", stdout);
}

void setIO() {
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);
}

void changeFS() {
    std::string path = "./../";
    std::filesystem::current_path(path);
}

namespace algorithm {
    std::bitset<32> A, B, C, D;

    // 1) append bits so that the length of  message in bits = k * 512 + 448 
    // 2  append the  64 bit length of the messge to make it = k * 512
    // 3) initilialize the output buffers 
    // 4) process the  input
    // 5) generate the output out of it

    // then combine all 
    // all functions use vec instead of bitset for functionality

    std::vector<bool> vec_from_message(std::string msg) {
        std::vector<bool> r;

        for (signed char c : msg) {
            std::vector<bool> i = vec_from_bitset8s(bitset8s_from_uchar(static_cast<unsigned char>(c)));
            r.insert(std::end(r), std::begin(i), std::end(i));
        }

        return r;
    }

    size_t calculate_to_add(size_t sz) {
        assert(sz >= 0 && sz <= 511);

        if (sz == 0) {
            return 448;
        }
        else if (sz < 448) {
            return (448 - sz);
        }
        else {
            return (512 - (sz - 448));
        }
    }

    std::vector<bool> apply_padding(std::vector<bool>& vec) {
        size_t sz = vec.size();
        size_t toadd = calculate_to_add(sz % 512);

        vec.push_back(true), toadd -= 1; // 1 added

        for (int i = 0;i < toadd;i++) vec.push_back(false);
        return vec;
    }

    /**
     * \brief
     * appends the size of original message (64bits) into vector of bool
     *
     * \param vec reference to vector bool of messages
     * \param sz size of the original message before padding
    */
    void append_size(std::vector<bool>& vec, size_t sz) {
        std::vector<bool> szvec = vec_from_size_t(sz);
        assert(szvec.size() == 64);
        vec.insert(std::end(vec), std::begin(szvec), std::end(szvec));
    }

    void initialize_buffers() {
        auto int_to_bitset = [](int32_t a) -> std::bitset<32UL> {
            std::bitset<32UL> f;
            f.reset();

            for (int i = 0;i < 32;i++) {
                if (((a >> i) & 1) != 0) {
                    f.set(i, true);
                }
            }

            return f;
            };

        A = int_to_bitset(0x01234567);
        B = int_to_bitset(0x89abcdef);
        C = int_to_bitset(0xfedcba98);
        D = int_to_bitset(0x76543210);
    }

#define F(x,y,z) (x & y) | ((~x) & z)
#define G(x,y,z) (x & y) | (y & z) | (z & x)
#define H(x,y,z) x ^ y ^ z

#define OPS1(a,b,c,d,k,s) a = left_rotate(add(add(a,F(b,c,d)),iter[k]),s)
#define OPS2(a,b,c,d,k,s) a = left_rotate(add(add(add(a,G(b,c,d)),iter[k]),0x5A827999),s)
#define OPS3(a,b,c,d,k,s) a = left_rotate(add(add(add(a,H(b,c,d)),iter[k]),0x6ED9EBA1),s)

    void populate_buffers(std::vector<bool> vec) {
        std::vector<int32_t> num; // 32 bit numbers (mul of 16)
        assert(vec.size() % 512 == 0);

        for (int i = 0;i < vec.size() / 32;i++) {
            int32_t t = 0;
            for (int j = 0;j < 32;j++) {
                t = (2 * t) + (vec[32 * i + j] ? 1 : 0);
            }
            num.push_back(t);
        }

        // for (int i = 0;i < num.size();i++) {
        //     std::cout << num[i] << " ";
        // }

        // std::cout << "\n";

        std::vector<int32_t> iter;

        for (int i = 0;i < num.size() / 16;i++) {
            iter.clear();// stores all 16 int32_t numbers for one iteration
            iter.resize(16);

            for (int j = 0;j < 15;j++) {
                iter[j] = num[16 * i + j];
            }

            std::bitset<32UL> AA = A, BB = B, CC = C, DD = D;
            // Round -1
            /*
                [ABCD  0  3]  [DABC  1  7]  [CDAB  2 11]  [BCDA  3 19]
                [ABCD  4  3]  [DABC  5  7]  [CDAB  6 11]  [BCDA  7 19]
                [ABCD  8  3]  [DABC  9  7]  [CDAB 10 11]  [BCDA 11 19]
                [ABCD 12  3]  [DABC 13  7]  [CDAB 14 11]  [BCDA 15 19]
            */
            OPS1(A, B, C, D, 0, 3);
            OPS1(D, A, B, C, 1, 7);
            OPS1(C, D, A, B, 2, 11);
            OPS1(B, C, D, A, 3, 19);

            OPS1(A, B, C, D, 4, 3);
            OPS1(D, A, B, C, 5, 7);
            OPS1(C, D, A, B, 6, 11);
            OPS1(B, C, D, A, 7, 19);

            OPS1(A, B, C, D, 8, 3);
            OPS1(D, A, B, C, 9, 7);
            OPS1(C, D, A, B, 10, 11);
            OPS1(B, C, D, A, 11, 19);

            OPS1(A, B, C, D, 12, 3);
            OPS1(D, A, B, C, 13, 7);
            OPS1(C, D, A, B, 14, 11);
            OPS1(B, C, D, A, 15, 19);

            // Round -2
            /**
                [ABCD  0  3]  [DABC  4  5]  [CDAB  8  9]  [BCDA 12 13]
                [ABCD  1  3]  [DABC  5  5]  [CDAB  9  9]  [BCDA 13 13]
                [ABCD  2  3]  [DABC  6  5]  [CDAB 10  9]  [BCDA 14 13]
                [ABCD  3  3]  [DABC  7  5]  [CDAB 11  9]  [BCDA 15 13]
            */

            OPS2(A, B, C, D, 0, 3);
            OPS2(D, A, B, C, 4, 5);
            OPS2(C, D, A, B, 8, 9);
            OPS2(B, C, D, A, 12, 13);

            OPS2(A, B, C, D, 1, 3);
            OPS2(D, A, B, C, 5, 5);
            OPS2(C, D, A, B, 9, 9);
            OPS2(B, C, D, A, 13, 13);

            OPS2(A, B, C, D, 2, 3);
            OPS2(D, A, B, C, 6, 5);
            OPS2(C, D, A, B, 10, 9);
            OPS2(B, C, D, A, 14, 13);

            OPS2(A, B, C, D, 3, 3);
            OPS2(D, A, B, C, 7, 5);
            OPS2(C, D, A, B, 11, 9);
            OPS2(B, C, D, A, 15, 13);

            // Round -3
            /**
                [ABCD  0  3]  [DABC  8  9]  [CDAB  4 11]  [BCDA 12 15]
                [ABCD  2  3]  [DABC 10  9]  [CDAB  6 11]  [BCDA 14 15]
                [ABCD  1  3]  [DABC  9  9]  [CDAB  5 11]  [BCDA 13 15]
                [ABCD  3  3]  [DABC 11  9]  [CDAB  7 11]  [BCDA 15 15]
            */

            OPS3(A, B, C, D, 0, 3);
            OPS3(D, A, B, C, 8, 9);
            OPS3(C, D, A, B, 4, 11);
            OPS3(B, C, D, A, 12, 15);

            OPS3(A, B, C, D, 2, 3);
            OPS3(D, A, B, C, 10, 9);
            OPS3(C, D, A, B, 6, 11);
            OPS3(B, C, D, A, 14, 15);

            OPS3(A, B, C, D, 1, 3);
            OPS3(D, A, B, C, 9, 9);
            OPS3(C, D, A, B, 5, 11);
            OPS3(B, C, D, A, 13, 15);

            OPS3(A, B, C, D, 3, 3);
            OPS3(D, A, B, C, 11, 9);
            OPS3(C, D, A, B, 7, 11);
            OPS3(B, C, D, A, 15, 15);

            A = add(A, AA);
            B = add(B, BB);
            C = add(C, CC);
            D = add(D, DD);
        }

    }

    std::string generate_digest() {
        std::string res;
        res.append(string_from_bitset(D));
        res.append(string_from_bitset(C));
        res.append(string_from_bitset(B));
        res.append(string_from_bitset(A));
        return res;
    }

    std::vector<bool> v1;

    std::string md4(std::string msg) {
        initialize_buffers();

        std::vector<bool> vec = vec_from_message(msg);
        // std::cout << vec.size() << "\n";
        apply_padding(vec);
        // std::cout << vec.size() << "\n";
        append_size(vec, msg.length());
        v1 = std::vector<bool>(vec.begin(), vec.end());
        populate_buffers(vec);
        return generate_digest();
    }

}

void init() {
    changeFS();
    redirectIO();
    setIO();
}

void __test() {
    std::bitset<32UL> bt(9), bt2;
    std::cout << bt << "\n";
    bt2 = left_rotate(bt, 0);
    std::cout << bt2 << "\n";
    std::cout << add(bt, bt2);

    // std::bitset<8UL> rbt = reverse_bitset_8s(bt);
    // std::cout << rbt << "\n";

    // algorithm::md4("12");
    // algorithm::print_buffers();
    // algorithm::initialize_buffers();
    // std::cout << string_from_bitset(algorithm::A) << "\n" << string_from_bitset(algorithm::B) <<"\n";
    // std::cout << algorithm::generate_digest();
}

void __main() {
    // std::cout << algorithm::md4("nishanth") << "\n";
    // std::vector<bool> v1, v2;
    // v1 = algorithm::v1;
    // std::cout << algorithm::md4("nishant") << "\n";
    // v2 = algorithm::v1;
    // std::cout << algorithm::md4("arun") << "\n";

    while (!std::cin.eof()) {
        std::string s;
        std::cin >> s;
        std::cout << "------BEGIN-DIGEST------\n";
        std::cout << algorithm::md4(s) << "\n-------END-DIGEST-------\n";

    }
}

int main(int argc, char* argv[]) {
    init();

#ifdef DEV_MODE
    __test();
#else 
    __main();
#endif

}