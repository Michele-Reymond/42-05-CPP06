#include <iostream>
#include "operations.hpp"

int main( void ) {

    // main donné dans le sujet
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    // autres tests
    char e = 'e';
    char f = 'f';

    std::cout << "e = " << e << ", f = " << f << std::endl;
    // instanciation explicite
    swap<char>(e,f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    // instanciation implicite
    swap(e,f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    return 0;
}