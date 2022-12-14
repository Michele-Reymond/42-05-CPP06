#include "header.hpp"

static int isChar(std::string arg) {
    if (arg.length() == 1 && isprint(arg[0]) && !isnumber(arg[0])) {
        return 1;
    }
    return 0;
}

static int isInt(std::string arg) {
    for (int i = 0; arg[i] != '\0'; i++) {
        if (!isnumber(arg[i]))
            return 0;
    }
    return 1;
}

int howMuchDecimals(std::string arg) {
    int i = 0;
    int j = 0;

    while (arg[i] != '\0') {
        if (arg[i] == '.')
            j -= i;
        if (arg[i] == 'f')
            j--;
        j++;
        i++;
    }
    j--;
    return (j);
}

static int isFloat(std::string arg) {
    float f;
    int decimals;

    decimals = howMuchDecimals(arg);
    std::istringstream(arg) >> f;
    std::stringstream s;
    s << std::fixed << std::setprecision(decimals) << f;
    std::string newS = s.str() + "f";
    if (arg == newS)
        return 1;
    return 0;
}

static int isDouble(std::string arg) {
    float f;
    int decimals;

    decimals = howMuchDecimals(arg);
    std::istringstream(arg) >> f;
    std::stringstream s;
    s << std::fixed << std::setprecision(decimals) << f;
    std::string newS = s.str();
    if (arg == newS)
        return 1;
    return 0;
}

static int isOther(std::string arg) {
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