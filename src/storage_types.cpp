#include "package.hpp"
#include "types.hpp"
#include "storage_types.hpp"

Package PackageQueue::pop()
{
    Package package(0);
    switch(queueType)
    {
        case (PackageQueueType::FIFO):
            package = Package(std::move(packageList.front()));
            packageList.pop_front();
            break;
        case (PackageQueueType::LIFO):
            package = Package(std::move(packageList.back()));
            packageList.pop_back();
            break;
    }
    return package;
}