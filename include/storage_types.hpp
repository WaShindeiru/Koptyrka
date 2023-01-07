#include "types.hpp"
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
    virtual void push(Package&&) = 0;
    virtual bool empty() = 0;
    using const_iterator = std::list<Package>::const_iterator;
    using size_type = std::list<Package>::size_type;
    virtual size_type size() = 0;
    virtual ~IPackageStockpile();
};

class IPackageQueue : IPackageStockpile{
public:
    virtual Package pop() ;
    virtual PackageQueueType get_queue_type();
};

class PackageQueue : IPackageQueue{
public:
    PackageQueue(PackageQueueType);
};


