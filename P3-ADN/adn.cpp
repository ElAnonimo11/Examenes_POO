
#include "adn.hpp"

#include <algorithm>

ADN::ADN() : n{0} , b{nullptr}
    {}

ADN::ADN(const Base &B) : n{1} , b{new Base[1]}
{
    std::fill_n(b,n,B);
}

ADN::ADN(const ADN &B) : n{B.n} , b{new Base[n]}
{
    std::copy_n(B.b,n,b);
}

ADN::ADN(ADN &&B) noexcept : n{B.n} , b{B.b}
{
    B.n = 0;
    B.b = nullptr;
}

ADN::~ADN()
{
    delete [] b;
}


