#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {
    public:

        Data(float nbr);
        Data(Data const &instance);
        ~Data();

        Data &operator=(Data const &instance);

        float   getNbr() const;
        void    setNbr(float f);

    private:
        float   _nbr;
};

#endif