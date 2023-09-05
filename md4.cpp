#include <iostream>
#include <string>
#include <random>
#include <cstdio>
#include <functional>
#include <filesystem>
#include <cassert>

#include "rand.hpp"

// #define DEV_MODE // excute test instead of main

void redirectIO() {

#ifndef TEST_IMODE
    freopen64("./input.in", "w+", stdin);
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

namespace util {
    int32_t F(int32_t x, int32_t y, int32_t z) {
        return (x & y) | ((~x) & z);
    }

    int32_t G(int32_t x, int32_t y, int32_t z) {
        return (x & y) | (y & z) | (z & x);
    }

    int32_t H(int32_t x, int32_t y, int32_t z) {
        return x ^ y ^ z;
    }


    int32_t left_rotate(int32_t num, int pl) {
        return (num << pl) | (num >> (32 - pl));
    }

    int32_t right_rotate(int32_t num, int pl) {
        return (num >> pl) | (num << (32 - pl));
    }
}

namespace algo {
    int32_t A, B, C, D;

    void initialize() {
        A = 19088743; // values set are pre defined
        B = 2309737967;
        C = 4275878552;
        D = 1985229328;
    }

    std::string pad_input(std::string msg) {
        std::string res = msg;
        int rem = msg.length() % 512;
        int toAdd = rem;

        if (rem == 448) {
            toAdd = 512;
        }
        else if (rem < 448) {
            toAdd = 448 - rem;
        }
        else {
            toAdd = 960 - rem;
        }

        res += "1", toAdd -= 1;

        for (int i = 0;i < toAdd;i++) {
            res += "0";
        }

        return res;
    }

    std::string append_length(std::string msg, std::string padded) {
        size_t len = msg.length();
        int32_t lower = static_cast<int32_t>(len); // losed in static conversion
        int32_t upper = static_cast<int32_t>(len >> 32);

        std::string res = msg;

        auto getChars = [](int32_t a) -> std::initializer_list<char> {
            std::initializer_list<char> res = { (char)a,
            (char)(a >> 8), (char)(a >> 16) , (char)(a >> 24) };

            return res;
            };

        res.append(getChars(lower)), res.append(getChars(upper));

        return res;
    }

    void process_buffer(std::string msg) {
        int64_t len = msg.length();

        std::function<std::vector<int32_t>(std::string)> split = [](std::string msg) -> std::vector<int32_t> {
            int64_t len = msg.length();
            len *= 8; // change len to bits
            std::cout << "len " << len <<"\n";
            std::cout.flush();
            std::cout << msg <<"\n";
            std::cout.flush();
            assert(len % 512 == 0); // len = 512 * k in bits = 64 * k in bytes = 16 * k in words
            len /= 32; // each contains 32 bits (a word)

            std::vector<int32_t> res;
            for (int i = 0;i < len;i += 4) {
                // each char => 1 byte => we need 4 bytes (a word)
                // msg[i] mg[i+1] msg[i+2] msg[i+3]
                int32_t r = 0;
                r += static_cast<int32_t>(msg[i] << 24);
                r += static_cast<int32_t>(msg[i + 1] << 16);
                r += static_cast<int32_t>(msg[i + 2] << 8);
                r += static_cast<int32_t>(msg[i + 3]);

                res.push_back(r);
            }

            return res;
            };

        std::vector<int32_t> words = split(msg);

        // len = no of words in string
        // len /= 16; // len = no of 16 words
        std::vector<int32_t> nums;

        for (int64_t i = 0;i < words.size() / 16;i++) {
            nums.clear();
            for (int64_t j = 0; j < 15;j++) {
                nums.push_back(words[16 * i + j]);

                int32_t AA = A, BB = B, CC = C, DD = D;

                A = util::left_rotate((A + util::F(B, C, D) + nums[0]), 3);
                D = util::left_rotate((D + util::F(A, B, C) + nums[1]), 7);
                C = util::left_rotate((C + util::F(D, A, B) + nums[2]), 11);
                B = util::left_rotate((B + util::F(C, D, A) + nums[3]), 19);

                A = util::left_rotate((A + util::F(B, C, D) + nums[4]), 3);
                D = util::left_rotate((D + util::F(A, B, C) + nums[5]), 7);
                C = util::left_rotate((C + util::F(D, A, B) + nums[6]), 11);
                B = util::left_rotate((B + util::F(C, D, A) + nums[7]), 19);

                A = util::left_rotate((A + util::F(B, C, D) + nums[8]), 3);
                D = util::left_rotate((D + util::F(A, B, C) + nums[9]), 7);
                C = util::left_rotate((C + util::F(D, A, B) + nums[10]), 11);
                B = util::left_rotate((B + util::F(C, D, A) + nums[11]), 19);

                A = util::left_rotate((A + util::F(B, C, D) + nums[12]), 3);
                D = util::left_rotate((D + util::F(A, B, C) + nums[13]), 7);
                C = util::left_rotate((C + util::F(D, A, B) + nums[14]), 11);
                B = util::left_rotate((B + util::F(C, D, A) + nums[15]), 19);

                // a = (a + G(b,c,d) + X[k] + 5A827999) <<< s
                /**
                 *  [ABCD  0  3]  [DABC  4  5]  [CDAB  8  9]  [BCDA 12 13]
                    [ABCD  1  3]  [DABC  5  5]  [CDAB  9  9]  [BCDA 13 13]
                    [ABCD  2  3]  [DABC  6  5]  [CDAB 10  9]  [BCDA 14 13]
                    [ABCD  3  3]  [DABC  7  5]  [CDAB 11  9]  [BCDA 15 13]
                */

                A = util::left_rotate((A + util::G(B, C, D) + nums[0] + static_cast<int32_t>(0x5A827999)), 3);
                D = util::left_rotate((D + util::G(A, B, C) + nums[4] + static_cast<int32_t>(0x5A827999)), 5);
                C = util::left_rotate((C + util::G(D, A, B) + nums[8] + static_cast<int32_t>(0x5A827999)), 9);
                B = util::left_rotate((B + util::G(C, D, A) + nums[12] + static_cast<int32_t>(0x5A827999)), 13);

                A = util::left_rotate((A + util::G(B, C, D) + nums[1] + static_cast<int32_t>(0x5A827999)), 3);
                D = util::left_rotate((D + util::G(A, B, C) + nums[5] + static_cast<int32_t>(0x5A827999)), 5);
                C = util::left_rotate((C + util::G(D, A, B) + nums[9] + static_cast<int32_t>(0x5A827999)), 9);
                B = util::left_rotate((B + util::G(C, D, A) + nums[13] + static_cast<int32_t>(0x5A827999)), 13);

                A = util::left_rotate((A + util::G(B, C, D) + nums[2] + static_cast<int32_t>(0x5A827999)), 3);
                D = util::left_rotate((D + util::G(A, B, C) + nums[6] + static_cast<int32_t>(0x5A827999)), 5);
                C = util::left_rotate((C + util::G(D, A, B) + nums[10] + static_cast<int32_t>(0x5A827999)), 9);
                B = util::left_rotate((B + util::G(C, D, A) + nums[14] + static_cast<int32_t>(0x5A827999)), 13);

                A = util::left_rotate((A + util::G(B, C, D) + nums[3] + static_cast<int32_t>(0x5A827999)), 3);
                D = util::left_rotate((D + util::G(A, B, C) + nums[7] + static_cast<int32_t>(0x5A827999)), 5);
                C = util::left_rotate((C + util::G(D, A, B) + nums[11] + static_cast<int32_t>(0x5A827999)), 9);
                B = util::left_rotate((B + util::G(C, D, A) + nums[15] + static_cast<int32_t>(0x5A827999)), 13);

                // a = (a + H(b,c,d) + X[k] + 6ED9EBA1) <<< s
                /**
                *   [ABCD  0  3]  [DABC  8  9]  [CDAB  4 11]  [BCDA 12 15]
                    [ABCD  2  3]  [DABC 10  9]  [CDAB  6 11]  [BCDA 14 15]
                    [ABCD  1  3]  [DABC  9  9]  [CDAB  5 11]  [BCDA 13 15]
                    [ABCD  3  3]  [DABC 11  9]  [CDAB  7 11]  [BCDA 15 15]
                */

                A = util::left_rotate((A + util::H(B, C, D) + nums[0] + static_cast<int32_t>(0x6ED9EBA1)), 3);
                D = util::left_rotate((D + util::H(A, B, C) + nums[8] + static_cast<int32_t>(0x6ED9EBA1)), 9);
                C = util::left_rotate((C + util::H(D, A, B) + nums[4] + static_cast<int32_t>(0x6ED9EBA1)), 11);
                B = util::left_rotate((B + util::H(C, D, A) + nums[12] + static_cast<int32_t>(0x6ED9EBA1)), 15);

                A = util::left_rotate((A + util::H(B, C, D) + nums[2] + static_cast<int32_t>(0x6ED9EBA1)), 3);
                D = util::left_rotate((D + util::H(A, B, C) + nums[10] + static_cast<int32_t>(0x6ED9EBA1)), 9);
                C = util::left_rotate((C + util::H(D, A, B) + nums[6] + static_cast<int32_t>(0x6ED9EBA1)), 11);
                B = util::left_rotate((B + util::H(C, D, A) + nums[14] + static_cast<int32_t>(0x6ED9EBA1)), 15);

                A = util::left_rotate((A + util::H(B, C, D) + nums[1] + static_cast<int32_t>(0x6ED9EBA1)), 3);
                D = util::left_rotate((D + util::H(A, B, C) + nums[9] + static_cast<int32_t>(0x6ED9EBA1)), 9);
                C = util::left_rotate((C + util::H(D, A, B) + nums[5] + static_cast<int32_t>(0x6ED9EBA1)), 11);
                B = util::left_rotate((B + util::H(C, D, A) + nums[13] + static_cast<int32_t>(0x6ED9EBA1)), 15);

                A = util::left_rotate((A + util::G(B, C, D) + nums[3] + static_cast<int32_t>(0x6ED9EBA1)), 3);
                D = util::left_rotate((D + util::G(A, B, C) + nums[11] + static_cast<int32_t>(0x6ED9EBA1)), 9);
                C = util::left_rotate((C + util::G(D, A, B) + nums[7] + static_cast<int32_t>(0x6ED9EBA1)), 11);
                B = util::left_rotate((B + util::G(C, D, A) + nums[15] + static_cast<int32_t>(0x6ED9EBA1)), 15);

                A = A + AA;
                B = B + BB;
                C = C + CC;
                D = D + DD;
            }
        }
    }

    std::string gen_digest() {
        std::string res;

        auto get_char = [](int32_t a) -> std::initializer_list<char> {
            char a1, a2, a3, a4;

            a1 = (unsigned char)(a & 0xff);
            a2 = (unsigned char)((a >> 8) & 0xff);
            a3 = (unsigned char)((a >> 16) & 0xff);
            a4 = (unsigned char)((a >> 24) & 0xff);

            return { a1,a2,a3,a4 };
            };

        res.append(get_char(D));
        res.append(get_char(C));
        res.append(get_char(B));
        res.append(get_char(A));

        return res;
    }

    std::string process_all(std::string msg) {
        std::string pad_msg = pad_input(msg);
        std::string app_len = append_length(msg, pad_msg);
        process_buffer(app_len);

        std::string digest = gen_digest();
        return digest;
    }
}

void init() {
    changeFS();
    redirectIO();
    setIO();
}

void __test() {
    std::cout << rnd::new_string(449);
}

void __main() {
    std::string msg;
    std::cin >> msg;

    algo::initialize();
    std::cout << algo::process_all(msg);
}

int main(int argc, char* argv[]) {
    init();

#ifdef DEV_MODE
    __test();
#else 
    __main();
#endif

}