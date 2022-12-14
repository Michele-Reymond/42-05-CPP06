# include "Data.hpp"

uintptr_t       serialize(Data *ptr);
Data            *deserialize(uintptr_t raw);

int main() {
    Data oldData = Data(12.5f);

	uintptr_t ptr = serialize(&oldData);
    Data *newData = deserialize(ptr);

    std::cout << std::endl << "befor: " << &oldData << std::endl;
    std::cout << "Nbr: " << oldData.getNbr() << std::endl << std::endl;
    
	std::cout << "serialization: " << ptr << std::endl << std::endl;

	std::cout << "after: " << newData << std::endl;
    std::cout << "Nbr: " << newData->getNbr() << std::endl << std::endl;

    std::cout << "oldData nbr befor: " << oldData.getNbr() << std::endl;
    std::cout << "newData nbr before: " << newData->getNbr() << std::endl << std::endl;

    oldData.setNbr(0.4f);

    std::cout << "oldData nbr after: " << oldData.getNbr() << std::endl;
    std::cout << "newData nbr after: " << newData->getNbr() << std::endl << std::endl;

    return 0;
}

// uintptr_t is an unsigned integer type that is capable of storing a 
// data pointer (whether it can hold a function pointer is unspecified). 
// Which typically means that it's the same size as a pointer.

// It is optionally defined in C++11 and later standards.

// A common reason to want an integer type that can hold an architecture's 
// pointer type is to perform integer-specific operations on a pointer, or to 
// obscure the type of a pointer by providing it as an integer "handle".