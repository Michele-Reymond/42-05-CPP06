#include <iostream>
#include <string>
#include <sstream>
# include <cstdlib>
# include <iomanip>
# include <cmath>

typedef enum e_types
{
	Char,
	Int,
	Float,
	Double,
    Nanf,
    InffMin,
    InffMax,
    Nan,
    InfMin,
    InfMax
}	t_types;

int isChar(std::string arg) {
    if (arg.length() == 1 && isprint(arg[0]) && !isnumber(arg[0])) {
        return 1;
    }
    return 0;
}

int isInt(std::string arg) {
    for (int i = 0; arg[i] != '\0'; i++) {
        if (!isnumber(arg[i]))
            return 0;
    }
    return 1;
}

int isFloat(std::string arg) {
    float f;

    std::istringstream(arg) >> f;
    std::stringstream s;
    s << std::fixed << std::setprecision(1) << f;
    std::string newS = s.str() + "f";
    if (arg == newS)
        return 1;
    return 0;
}

int isDouble(std::string arg) {
    float f;

    std::istringstream(arg) >> f;
    std::stringstream s;
    s << f;
    std::string newS = s.str();
    if (arg == newS)
        return 1;
    return 0;
}

int isOther(std::string arg) {
    if (arg == "nanf")
        return Nanf;
    else if (arg == "-inff")
        return InffMin;
    else if (arg == "+inff")
        return InffMax;
    else if (arg == "nan")
        return Nan;
    else if (arg == "-inf")
        return InfMin;
    else if (arg == "+inf")
        return InfMax;
    else
        return -1;
}

int what_kind(std::string arg) {
    if (isChar(arg))
        return Char;
    else if (isInt(arg))
        return Int;
    else if (isFloat(arg))
        return Float;
    else if (isDouble(arg))
        return Double;
    else
        return isOther(arg);
}

void printChar(char c) {
	std::cout << "char: ";
	if (isprint(c) && !isnumber(c))
		std::cout << c << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void printInt(int i) {
	std::cout << "int: ";
	std::cout << i << std::endl;
}

void printFloat(float f) {
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void printDouble(double d) {
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

void convert(void *what, int kind) {
    if (kind == Char) {
        printChar(static_cast<char>(*(char *)what));
        printInt(static_cast<int>(*(char *)what));
        printFloat(static_cast<float>(*(char *)what));
        printDouble(static_cast<double>(*(char *)what));
    }
    else if (kind == Int) {
        printChar(static_cast<char>(*(int *)what));
        printInt(static_cast<int>(*(int *)what));
        printFloat(static_cast<float>(*(int *)what));
        printDouble(static_cast<double>(*(int *)what));
    }
    else if (kind == Float) {
        printChar(static_cast<char>(*(float *)what));
        printInt(static_cast<int>(*(float *)what));
        printFloat(static_cast<float>(*(float *)what));
        printDouble(static_cast<double>(*(float *)what));
    }
    else if (kind == Double) {
        printChar(static_cast<char>(*(double *)what));
        printInt(static_cast<int>(*(double *)what));
        printFloat(static_cast<float>(*(double *)what));
        printDouble(static_cast<double>(*(double *)what));
    }
}


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "You must give to this programme only one agrument" << std::endl;
        return 1;
    }
    int kind = what_kind(argv[1]);
    if (kind == Char) {
        char c = argv[1][0];
        convert(&c, Char);
    }
    else if (kind == Int) {
        int i = atoi(argv[1]);
        convert(&i, Int);
    }
    else if (kind == Float) {
        float f = atof(argv[1]);
        convert(&f, Float);
    }
    else if (kind == Double) {
        double d = atof(argv[1]);
        convert(&d, Double);
    }
    // else if (kind >= Nanf && kind <= InfMax)
    //     printOther(argv[1]);
    else
        std::cout << "Conversion not possible" << std::endl;
    return 0;
}