#ifndef OPERATIONS_HPP
# define OPERATIONS_HPP

template< typename T>
void swap(T & x, T & y) {
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
}

template< typename T>
T const & min(T const & x, T const & y) {
    if (x == y)
        return (y);
    return (x < y ? x : y);
}

template< typename T>
T const & max(T const & x, T const & y) {
    if (x == y)
        return (y);
    return (x > y ? x : y);
}

#endif