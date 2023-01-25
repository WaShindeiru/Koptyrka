#include "package.hpp"

Package::Package(){
    if (freed_IDs.empty()) {
        ID = assigned_IDs.size() + 1;
        assigned_IDs.insert(ID);
    } else {
        ID = *freed_IDs.begin();
        freed_IDs.erase(ID);
    }
};

Package::Package(ElementID Id){
    ID = Id;
    assigned_IDs.insert(ID);
};

Package::Package(Package&& other) : ID(other.get_id()){


}

Package& Package::operator=(Package&& other){
    ID = other.get_id();
    return *this;

};

ElementID Package::get_id() const{
    return ID;
};

Package::~Package(){
    freed_IDs.insert(ID);
    assigned_IDs.erase(ID);
}


std::set<ElementID> Package::assigned_IDs;
std::set<ElementID> Package::freed_IDs;

