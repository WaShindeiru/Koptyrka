#include "types.hpp"
#include "storage_types.hpp"


#include <stdlib.h>
#include <list>
#include <vector>
#include <stdio.h>

enum PackageQueueType;

class PackageQueue : public IPackageQueue{
public:
    PackageQueue(PackageQueueType type) : queueType(type){};
    void push(Package&& package) override{
        packageList.emplace_back(std::move(package));
    }

    bool empty() override{
        return packageList.empty();
    }

    size_type size() override{
        return packageList.size();
    }

    const_iterator begin() override{
        return packageList.begin();
    }

    const_iterator end() override{
        return packageList.end();
    }

    const_iterator cbegin() const override{
        return packageList.cbegin();
    }

    const_iterator cend() const override{
        return packageList.cend();
    }

    PackageQueueType get_queue_type() const override{
        return queueType;
    }

    //jakas lipa
    Package pop() override{
        switch(queueType){
            case FIFO:
                 auto package = *cbegin();
                 packageList.pop_front();
                 return package;
                 break;

            case LIFO:
                auto package = *cend();
                packageList.pop_back();
                return package;
                break;
        }
    }

    ~PackageQueue();

private:
    PackageQueueType queueType;
    std::list<Package> packageList;

};







