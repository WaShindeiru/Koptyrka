#ifndef storage_types_hpp
#define storage_types_hpp
#include "package.hpp"

#include <stdlib.h>
#include <list>
#include <vector>

enum PackageQueueType{
    FIFO,
    LIFO
};

class IPackageStockpile{
public:
    using size_type = std::list<Package>::size_type;
    using const_iterator = std::list<Package>::const_iterator;

    virtual void push(Package&& package) = 0;
    virtual bool empty() = 0;
    virtual size_type size() = 0;

    virtual const_iterator begin() = 0;
    virtual const_iterator end() = 0;
    virtual const_iterator cbegin() const = 0;
    virtual const_iterator cend() const = 0;

    virtual ~IPackageStockpile() = default;
};

class IPackageQueue : public IPackageStockpile{
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
};

#endif