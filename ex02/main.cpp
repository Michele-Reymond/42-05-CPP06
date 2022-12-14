# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base &p);

int main() {
    Base *base = generate();

    std::cout << std::endl << "identify pointer" << std::endl;
    identify(base);

    std::cout << std::endl << "identify reference" << std::endl;
    identify(*base);
    return 0;
}
