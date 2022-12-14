#include "header.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "You must give to this programme only one agrument" << std::endl;
        return 1;
    }
    int kind = what_kind(argv[1]);
    if (kind == Char) {
        char c = argv[1][0];
        convert(&c, Char, 1);
    }
    else if (kind == Int) {
        int i = atoi(argv[1]);
        convert(&i, Int, 1);
    }
    else if (kind == Float) {
        int decimals = howMuchDecimals(argv[1]);
        float f = atof(argv[1]);
        convert(&f, Float, decimals);
    }
    else if (kind == Double) {
        int decimals = howMuchDecimals(argv[1]);
        double d = atof(argv[1]);
        convert(&d, Double, decimals);
    }
    else if (kind >= Nanf && kind <= InfMax)
        printOther(kind);
    else
        std::cout << "Conversion not possible" << std::endl;
    return 0;
}