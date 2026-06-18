#include <iostream>
#include "Vector.h"

int main()
{
    constexpr npj::Vector<int, 1, npj::VectorSemantic::HSVA> a{1};

    std::cout << a.h << ", " << a.a << "\n";

    return 0;
}
