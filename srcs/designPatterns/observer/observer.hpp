#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <functional>
#include <unordered_map>
#include <vector>
template <typename TEvent>
class   Observer
{
    public:
        void    subscribe(const TEvent& event, const std::function<void()>& lambda) {
            _subscribed[event].push_back(lambda);
        }

        void    notify(const TEvent& event) {
            auto it = _subscribed.find(event);
            if (it != _subscribed.end())
                for (const auto& lambda : it->second)
                    lambda();
        }

    private:
        std::unordered_map<TEvent, std::vector<std::function<void()>>>  _subscribed;
};

#endif
