//
// Created by frane on 07/01/2023.
//

#ifndef KOT_PACKAGE_HPP
#define KOT_PACKAGE_HPP
#include <set>
#include <list>
#import "types.hpp"

class Package{
public:
    Package();
    Package(ElementID Id);
    Package(Package&& other);

    Package& operator=(Package&& other);

    ~Package();

private:
    static std::set<ElementID> assigned_IDs;
    static std::set<ElementID> freed_IDs;
    ElementID ID;
};

class IPackageStockpile{
public:
    using const_iterator = std::list<Package>::const_iterator;

    virtual void push(Package&& package) = 0;
    virtual bool empty() = 0;
    virtual size_t size() = 0;
    virtual const_iterator begin() = 0;
    virtual const_iterator end() = 0;
    virtual const_iterator cbegin() = 0;
    virtual const_iterator cend() = 0;

    virtual ~IPackageStockpile() = default;

};

class IPackageQueue : public IPackageStockpile{
public:
    void push(Package&& package);
    bool empty();
    size_t size();
    const_iterator begin();
    const_iterator end();
    const_iterator cbegin();
    const_iterator cend();

    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() = 0;

    virtual ~IPackageQueue() = default;

protected:
    std::list<Package> packages;
};
#endif //KOT_PACKAGE_HPP
