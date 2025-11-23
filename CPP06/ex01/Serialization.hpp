#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>

struct Data
{
   int value;
   std::string str; 
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &Sr);
        Serializer& operator=(const Serializer &Sr);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
