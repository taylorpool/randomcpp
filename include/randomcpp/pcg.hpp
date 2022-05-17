#pragma once
#include <cstdint>

namespace randomcpp
{

    class PCGRS
    {
        public:
            uint64_t a;
            uint64_t c;

        private:
            uint64_t state;

        public:

            PCGRS(uint64_t _a, uint64_t _c, uint64_t seed)
            : a(_a), c(_c), state(seed) {}

            uint32_t operator()()
            {
                state = state*a + c;
                return state >> (29 - (state >> 61));
            }
    };

    uint32_t rotate(uint32_t x, unsigned r)
    {
        return x >> r | x << (-r & 31);
    }

    class PCG32
    {
        public:
            static const uint64_t multiplier = 6364136223846793005u;
            const uint64_t increment;

        private:
            uint64_t state;

        public:
            PCG32(uint64_t _seed, uint64_t _increment = 1442695040888963407u)
            : increment(_increment)
            {
                state = _seed + increment;
            }

            uint32_t operator()()
            {
                uint64_t x = state;
                unsigned count = static_cast<unsigned>(x >> 59);

                state = x*multiplier + increment;
                x ^= x >> 18;
                return rotate(static_cast<uint32_t>(x >> 27), count);
            }
    };
}