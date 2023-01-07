#include "types.hpp"

class Package {
public:
    Package();
    Package(ElementID);
    Package(Package&&);
    Package& operator = (Package&& other){
        ID = other.ID;
        return *this;

    }
    ElementID get_id();
    ~Package();

private:
    ElementID ID;


};