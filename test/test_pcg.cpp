#include "randomcpp/pcg.hpp"

#include <iostream>

using namespace randomcpp;

int main(int argc, char* argv[])
{
    PCG32 pcg32(0x4d595df4d0f33173u);
    for(int trial = 0; trial < 1000; ++trial)
    {
        uint32_t value = pcg32();
        std::cout << value/static_cast<double>(UINT32_MAX) << std::endl;
    }

    return 0;
}