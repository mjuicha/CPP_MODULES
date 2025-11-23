#include "Serialization.hpp"

int main()
{
    Data data;
    data.value = 42;
    data.str = "Hello, World!";

    std::cout << "Original Data pointer: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized data pointer: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;

    std::cout << "Deserialized Data value: " << deserializedData->value << std::endl;
    std::cout << "Deserialized Data string: " << deserializedData->str << std::endl;

    return 0;
}