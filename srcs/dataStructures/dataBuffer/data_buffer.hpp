#ifndef DATA_BUFFER_HPP
#define DATA_BUFFER_HPP

#include <vector>
#include <iostream>
#include <cstring>

class   dataBuffer
{
    public:
        template<typename T>
        dataBuffer& operator<<(const T& obj);

        template<typename T>
        dataBuffer& operator>>(T& obj);

    private:
        std::vector<char> _buffer;
};

template<typename T>
dataBuffer& dataBuffer::operator<<(const T& obj)
{
    static_assert(std::is_trivially_copyable<T>::value, "Type must be trivially copyable");
    const char* data = reinterpret_cast<const char*>(&obj);
    _buffer.insert(_buffer.end(), data, data + sizeof(T));
    return *this;
}

template<typename T>
dataBuffer& dataBuffer::operator>>(T& obj)
{
    static_assert(std::is_trivially_copyable<T>::value, "Type must be trivially copyable");
    if (_buffer.size() < sizeof(T))
        throw std::runtime_error("Not enough data in buffer to deserialize");

    std::memcpy(&obj, _buffer.data(), sizeof(T));
    _buffer.erase(_buffer.begin(), _buffer.begin() + sizeof(T));
    return *this;
}

#endif
