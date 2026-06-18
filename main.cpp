#include <iostream>
#include "Vector.h"

int main()
{
    constexpr npj::Vector<int, 4, npj::VectorSemantic::HSVA> a{1,2,3,4};

    std::cout << a.h << ", " << a.a << "\n";

    return 0;
}
