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
    - [Observer](#observer)
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
#include "pool.hpp"
#include <iostream>
#include <stdexcept>

struct TestObject {
    int value;

    TestObject() : value(0) {
        std::cout << "Default constructed TestObject with value: " << value << std::endl;
    }

    TestObject(int v) : value(v) {
        std::cout << "Constructed TestObject with value: " << value << std::endl;
    }

    ~TestObject() {
        std::cout << "Destroyed TestObject with value: " << value << std::endl;
    }

    void print() const {
        std::cout << "TestObject value: " << value << std::endl;
    }
};

int main() {
    Pool<TestObject> pool;

    pool.resize(3);

    try {
        auto obj1 = pool.acquire(10);
        obj1->print();
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        auto obj2 = pool.acquire(20);
        obj2->print();
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        auto obj3 = pool.acquire(30);
        obj3->print();
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        auto obj4 = pool.acquire(40);
        obj4->print();
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

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

#### Observer

The Observer Pattern is a behavioral design pattern that defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically normally.

```cpp
#include "observer.hpp"
#include <iostream>

enum class EventType { Start, Stop, Pause, Resume };

int main() {
    Observer<EventType> observer;

    observer.subscribe(EventType::Start, []() {
        std::cout << "[Listener 1] Start event triggered!" << std::endl;
    });

    observer.subscribe(EventType::Start, []() {
        std::cout << "[Listener 2] Starting some initialization process..." << std::endl;
    });

    observer.subscribe(EventType::Stop, []() {
        std::cout << "[Listener 1] Stop event triggered! Shutting down." << std::endl;
    });

    observer.subscribe(EventType::Pause, []() {
        std::cout << "[Listener 1] Pause event: Pausing the system." << std::endl;
    });

    observer.subscribe(EventType::Pause, []() {
        std::cout << "[Listener 2] Pause event: Saving current state..." << std::endl;
    });

    observer.subscribe(EventType::Resume, []() {
        std::cout << "[Listener 1] Resume event: System resuming from pause." << std::endl;
    });

    std::cout << "Triggering Start event..." << std::endl;
    observer.notify(EventType::Start);

    std::cout << "\nTriggering Pause event..." << std::endl;
    observer.notify(EventType::Pause);

    std::cout << "\nTriggering Resume event..." << std::endl;
    observer.notify(EventType::Resume);

    std::cout << "\nTriggering Stop event..." << std::endl;
    observer.notify(EventType::Stop);

    return 0;
}
```

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
