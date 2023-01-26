#ifndef NETSIM_PACKAGE_HPP
#define NETSIM_PACKAGE_HPP

#include "types.hpp"
#include <vector>

class Package{
public:
    Package();
    explicit Package(ElementID);
    Package(Package&&) noexcept;
    Package& operator = (Package&&) noexcept;
    ElementID get_id() const {return ID_;};
    ~Package();

private:
    static std::vector<ElementID> usedlist;
    static std::vector<ElementID> freelist;
    ElementID ID_;
};


#endif

