# 🚀 42_LIBFTPP

A C++ toolkit for some advanced topics like data pools, threading, networking, etc. It is a part of the 42 Post Common Core projects. The goal of this project is to create a library that can be used in future projects. The library is written in C++ and is normally full cross-platform.

## 📚 Table of Contents

- [🔧 Installation](#installation)
- [🌟 Getting Started](#getting-started)
- [✨ Tools](#tools)
  - [Data Structures](#data-structures)
    - [Pool](#pool)
    - [DataBuffer](#databuffer)
  - [Design Patterns](#design-patterns)
  - [IOStrean](#iostream)
  - [Threading](#threading)
  - [Networking](#networking)
  - [Math](#math)
- [📝 License](#license)
- [👤 Author](#author)
- [📞 Contact](#contact)

## 🔧 Installation

```bash
git clone

cd 42_LIBFTPP

make
```

## 🌟 Getting Started

Copy the main.cpp file to your project and include the library for testing or run the test script that is provided in the repository.

```bash
./test.sh
```

## ✨ Tools

### Data Structures

#### Pool

The Pool class is a data structure that is used to store a collection of objects. The pool is a fixed-size data structure that is used to store objects of the same type. The pool is a memory-efficient data structure that is used to store objects of the same type.

```cpp
#include "pool.h"

int main() {
  Pool<int> pool(10);

  pool.add(1);
  pool.add(2);
  pool.add(3);

  pool.remove(2);

    return 0;
}
```

#### DataBuffer

The DataBuffer class is a data structure that is set up as a polymorphic container for storing objects as bytes.

```cpp
#include "data_buffer.hpp"
#include <iostream>

// Custom struct (must be trivially copyable)
struct MyStruct {
    int id;
    float value;
    bool flag;
};

int main() {
    dataBuffer buffer;

    // Data to serialize
    int intValue = 123;
    double doubleValue = 3.14159;
    char charValue = 'A';
    float floatValue = 1.618f;
    bool boolValue = true;
    MyStruct myStruct = {42, 9.81f, true};

    // Serialize (write) data into the buffer
    buffer << intValue << doubleValue << charValue << floatValue << boolValue << myStruct;

    // Deserialize (read) data from the buffer
    int deserializedInt;
    double deserializedDouble;
    char deserializedChar;
    float deserializedFloat;
    bool deserializedBool;
    MyStruct deserializedStruct;

    buffer >> deserializedInt >> deserializedDouble >> deserializedChar >> deserializedFloat >> deserializedBool >> deserializedStruct;

    // Output the deserialized values
    std::cout << "Deserialized int: " << deserializedInt << std::endl;
    std::cout << "Deserialized double: " << deserializedDouble << std::endl;
    std::cout << "Deserialized char: " << deserializedChar << std::endl;
    std::cout << "Deserialized float: " << deserializedFloat << std::endl;
    std::cout << "Deserialized bool: " << std::boolalpha << deserializedBool << std::endl;
    std::cout << "Deserialized struct: { id: " << deserializedStruct.id << ", value: " << deserializedStruct.value << ", flag: " << deserializedStruct.flag << " }" << std::endl;

    return 0;
}
```

### Design Patterns

### IOStream

### Threading

### Networking

### Math

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Feel free to use the code in this repository as freely as you want, credit is not required but appreciated.

## 👤 Author

This project was developed fully by me. If you have any questions or suggestions, please feel free to contact me.

## 📞 Contact

- Email: [raymaekersq@gmail.com](mailto:)
- LinkedIn: [Quinten](https://www.linkedin.com/in/quinten-raymaekers-7763a6262/)
- GitHub: [Quinten](https://github.com/Quinten-14)
