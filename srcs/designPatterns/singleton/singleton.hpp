#ifndef SINGLETON_HPP
# define SINGLETON_HPP

#include <stdexcept>
#include <utility>

template<typename TType>
class   Singleton
{
    public:
        static TType* instance() {
            if (!_instance)
                throw std::runtime_error("No instance yet.");
            return _instance;
        }

        template<typename ... TArgs>
        static void instanciate(TArgs&&... p_args) {
            if (_instance)
                throw std::runtime_error("Instance already instanciated.");
            _instance = new TType(std::forward<TArgs>(p_args)...);
        }
    
    private:
        static TType*  _instance;
};

template<typename TType>
TType*  Singleton<TType>::_instance = nullptr;

#endif
