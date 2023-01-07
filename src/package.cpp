//
// Created by frane on 07/01/2023.
//

#include "../include/package.hpp"

std::set<ElementID> Package::assigned_IDs;
std::set<ElementID> Package::freed_IDs;

Package::Package() {
    if (freed_IDs.empty()) {
        ID = assigned_IDs.size() + 1;
        assigned_IDs.insert(ID);
    } else {
        ID = *freed_IDs.begin();
        freed_IDs.erase(ID);
    }
}

Package::Package(ElementID Id) {
    ID = Id;
    assigned_IDs.insert(ID);
}

Package::Package(Package &&other) {
    ID = other.ID;
}

Package &Package::operator=(Package &&other) {
    ID = other.ID;
    return *this;
}

Package::~Package() {
    freed_IDs.insert(ID);
    assigned_IDs.erase(ID);
}

void IPackageQueue::push(Package &&package) {
    packages.push_back(std::move(package));
}

bool IPackageQueue::empty() {
    return packages.empty();
}

size_t IPackageQueue::size() {
    return packages.size();
}

IPackageQueue::const_iterator IPackageQueue::begin() {
    return packages.begin();
}

IPackageQueue::const_iterator IPackageQueue::end() {
    return packages.end();
}

IPackageQueue::const_iterator IPackageQueue::cbegin() {
    return packages.cbegin();
}

IPackageQueue::const_iterator IPackageQueue::cend() {
    return packages.cend();
}