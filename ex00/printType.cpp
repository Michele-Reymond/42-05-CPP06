#include "header.hpp"

static void printChar(char c) {
	std::cout << "char: ";
	if (isprint(c) && !isnumber(c))
		std::cout << c << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

static void printInt(int i) {
	std::cout << "int: ";
	std::cout << i << std::endl;
}

static void printFloat(float f, int decimals) {
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(decimals) << f << "f" << std::endl;
}

static void printDouble(double d, int decimals) {
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(decimals) << d << std::endl;
}

void printOther(int kind) {
    float f;

    if (kind == Nan || kind == Nanf)
        f = NAN;
    if (kind == InfMax || kind == InffMax)
        f = INFINITY;
    if (kind == InffMin || kind == InfMin)
        f = -INFINITY;
    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: Non displayable" << std::endl;
    printFloat(static_cast<float>(f), 0);
    printDouble(static_cast<double>(f), 0);
}

void convert(void *what, int kind, int decimals) {
    if (kind == Char) {
        printChar(static_cast<char>(*(char *)what));
        printInt(static_cast<int>(*(char *)what));
        printFloat(static_cast<float>(*(char *)what), decimals);
        printDouble(static_cast<double>(*(char *)what), decimals);
    }
    else if (kind == Int) {
        printChar(static_cast<char>(*(int *)what));
        printInt(static_cast<int>(*(int *)what));
        printFloat(static_cast<float>(*(int *)what), decimals);
        printDouble(static_cast<double>(*(int *)what), decimals);
    }
    else if (kind == Float) {
        printChar(static_cast<char>(*(float *)what));
        printInt(static_cast<int>(*(float *)what));
        printFloat(static_cast<float>(*(float *)what), decimals);
        printDouble(static_cast<double>(*(float *)what), decimals);
    }
    else if (kind == Double) {
        printChar(static_cast<char>(*(double *)what));
        printInt(static_cast<int>(*(double *)what));
        printFloat(static_cast<float>(*(double *)what), decimals);
        printDouble(static_cast<double>(*(double *)what), decimals);
    }
}
