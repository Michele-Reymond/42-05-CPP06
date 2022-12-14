#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

int gerateRandom()
{
    srand(time(NULL));
    int randNum = (rand() % 3) + 1;
    return randNum;
}

Base * generate(void) {
    Base *base;
    int i = gerateRandom();
    if (i == 1) {
        base = new B;
    }
    else if (i == 2) {
        base = new C;
    }
    else {
        base = new A;
    }
    return (base);
}

// renvoie NULL si le dynamic cast n'est pas possible
void identify(Base* p) {
    if (dynamic_cast<A *>(p))
		std::cout << "True self is 'A'" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "True self is 'B'" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "True self is 'C'" << std::endl;
}

// crash si le dynamic cast n'est pas possible
void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << &a << " : True self is 'A'" << std::endl;
		return ;
	}
	catch (std::exception &e){
        std::cout << "It's not an 'A': " << e.what() << std::endl;
    }

	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << &b << " : True self is 'B'" << std::endl;
		return ;
	}
	catch (std::exception &e) {
        std::cout << "It's not a 'B': " << e.what() << std::endl;
    }

	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << &c << " : True self is 'C'" << std::endl;
		return ;
	}
	catch (std::exception &e) {
        std::cout << "It's not a 'C': " << e.what() << std::endl;
        std::cerr << "That means Self is too blurry to identify!" << std::endl;
    }
}