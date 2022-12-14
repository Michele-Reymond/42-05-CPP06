#ifndef HEADER_HPP
#define HEADER_HPP

# include <iostream>
# include <string>
# include <sstream>
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

int     what_kind(std::string arg);
int     howMuchDecimals(std::string arg);
void    printOther(int kind);
void    convert(void *what, int kind, int decimals);

#endif
