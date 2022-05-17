#include "randomcpp/lcg.hpp"

#include <iostream>

using namespace randomcpp;

int main(int argc, char* argv[])
{
    LCG rng;
    rng.a = 3;
    rng.c = 4;
    rng.m = 10;
    for(int trial = 0; trial < 100; ++trial)
    {
        std::cout << rng() << std::endl;
    }
    return 0;
}