#include "Serialization.hpp"

int main()
{
    Data data;

    data.value = 42;
    data.str = "Hello, World!";

    std::cout << "Original Data pointer: " << &data << std::endl;
    std::cout << std::endl;

    std::cout << "Serializing..." << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data pointer: " << raw << std::endl;
    std::cout << std::endl;

    std::cout << "Deserializing..." << std::endl;
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;
    std::cout << std::endl;

    if (deserializedData == &data)
    {
        std::cout << "Success: Deserialized pointer matches original pointer." << std::endl;
        std::cout << "Deserialized Data value: " << deserializedData->value << std::endl;
        std::cout << "Deserialized Data string: " << deserializedData->str << std::endl;
    }
    else
    {
        std::cout << "Error: Deserialized pointer does not match original pointer." << std::endl;
    }
    return 0;
}
