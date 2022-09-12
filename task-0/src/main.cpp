#include <iostream>
#include "rational/rational.hpp"

int main(){
    Rational_number l(-12, 10);
    l.simplify();
    std::cout << l.numerator << "; " << l.denominator << std::endl;
}