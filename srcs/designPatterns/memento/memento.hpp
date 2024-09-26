#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <unordered_map>
#include <string>
#include <any>

class   Memento
{
    public:
        class   Snapshot {
            public:
                std::unordered_map<std::string, std::any>   snapshotState;
        };

        Snapshot    save();

        void    load(const Memento::Snapshot& state);

    private:
        virtual void    saveToSnapshot(Snapshot &snapshot) const = 0;
        virtual void    loadFromSnapshot(const Snapshot &snapshot) = 0;

        friend class Saveable;
};

// Example code

class   Saveable : public Memento
{
    public:
        Saveable(std::string name, std::string lastName);
        void    printState() const;

    private:
        std::string _name;
        std::string _lastName;

        void    saveToSnapshot(Snapshot& snapshot) const override;
        void    loadFromSnapshot(const Snapshot& snapshot) override;
};

#endif
