#include "memento.hpp"
#include <any>
#include <iostream>

// Memento code

Memento::Snapshot   Memento::save()
{
    Snapshot    snapshot;
    saveToSnapshot(snapshot);
    return snapshot;
}

void    Memento::load(const Snapshot &snapshot)
{
    loadFromSnapshot(snapshot);
}

// Savable example code

Saveable::Saveable(std::string name, std::string lastName) : _name(name), _lastName(lastName) {}

void    Saveable::printState() const
{
    std::cout << "First name: " << _name << " and Last name: " << _lastName << std::endl;
}

void    Saveable::saveToSnapshot(Snapshot& snapshot) const
{
    snapshot.snapshotState["name"] = _name;
    snapshot.snapshotState["lastName"] = _lastName;
}

void    Saveable::loadFromSnapshot(const Snapshot& snapshot)
{
    if (snapshot.snapshotState.find("name") != snapshot.snapshotState.end())
        _name = std::any_cast<std::string>(snapshot.snapshotState.at("name"));
    if (snapshot.snapshotState.find("lastName") != snapshot.snapshotState.end())
        _lastName = std::any_cast<std::string>(snapshot.snapshotState.at("lastName"));
}
