#include "rand.hpp"

#include <random>
#include <chrono>
#include <climits>

namespace rnd {
    int64_t new_int64() {
        std::mt19937 source(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int64_t> engine(1,static_cast<int64_t>(INT64_MAX));

        return engine(source);
    }

    std::string new_string(int64_t len) {
        std::string res;

        std::uniform_int_distribution<int> decider(0, 1);
        std::uniform_int_distribution<char> alphas('a', 'z'), alphal('A', 'Z');

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        std::mt19937 decider_source(seed);
        std::ranlux48 sml_source(seed+3), lrg_source(seed);

        for (int64_t i = 0;i < len;i++) {
            int opt = decider(decider_source);
            if (opt == 0) {
                res.push_back(alphas(sml_source));
            }
            else {
                res.push_back(alphal(lrg_source));
            }
        }

        return res;
    }
}