#ifndef POOL_HPP
#define POOL_HPP

#include <cstddef>
#include <functional>
#include <memory>
#include <stack>
#include <stdexcept>
#include <utility>

template <typename TType>
class Pool {
public:
    template <typename U>
    class Object;

    void resize(const size_t& numberOfObjectStored) {
        for (size_t i = 0; i < numberOfObjectStored; ++i) {
            _freeObjects.push(new TType);
        }
    }

    template <typename... TArgs>
    Object<TType> acquire(TArgs&&... args) {
        if (_freeObjects.empty()) {
            throw std::runtime_error("No available objects in the pool");
        }

        TType* obj = _freeObjects.top();
        _freeObjects.pop();

        new (obj) TType(std::forward<TArgs>(args)...);

        return Object<TType>(obj, [this](TType* obj) {
            obj->~TType(); 
            _freeObjects.push(obj);
        });
    }

private:
    std::stack<TType*> _freeObjects;

public:
    template <typename U>
    class Object {
    public:
        Object(U* ptr, std::function<void(U*)> deleter)
            : _ptr(ptr), _deleter(deleter) {}

        ~Object() {
            if (_ptr) {
                _deleter(_ptr);
            }
        }

        U* operator->() const {
            return _ptr;
        }

    private:
        U* _ptr;
        std::function<void(U*)> _deleter;
    };
};

#endif

