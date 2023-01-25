#ifndef package_hpp
#define package_hpp

#include "types.hpp"
#include <set>

class Package {
public:
    Package();
    Package(ElementID Id);
    Package(Package&& other);

    Package& operator=(Package&& other);
    ElementID get_id() const;

    ~Package();

private:
    static std::set<ElementID> assigned_IDs;
    static std::set<ElementID> freed_IDs;
    ElementID ID;
};
#endif