#include "types.hpp"

class Package {
public:
    Package();
    Package(ElementID);
    Package(Package&&);
    Package& operator=(Package&&);
    ElementID get_id();
    ~Package();

private:


};