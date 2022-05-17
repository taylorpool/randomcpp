#pragma once

namespace randomcpp
{
class LCG
{
    public:
        int a;
        int c;
        int m;

    private:
        int state;

    public:
        int operator()()
        {
            state = (a*state + c) % m;
            return state;
        }
};
}