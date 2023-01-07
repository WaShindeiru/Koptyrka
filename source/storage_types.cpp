#include "storage_types.hpp"

#include <stdlib.h>
#include <list>
#include <vector>
#include <stdio.h>


    PackageQueue::PackageQueue(PackageQueueType type) : queueType(type){};

    void PackageQueue::push(Package&& package) {
        packageList.emplace_back(std::move(package));
    }

    bool PackageQueue::empty(){
        return packageList.empty();
    }

    size_type PackageQueue::size(){
        return packageList.size();
    }

    const_iterator PackageQueue::begin(){
        return packageList.begin();
    }

    const_iterator PackageQueue::end(){
        return packageList.end();
    }

    const_iterator PackageQueue::cbegin() const{
        return packageList.cbegin();
    }

    const_iterator PackageQueue::cend() const{
        return packageList.cend();
    }

    PackageQueueType PackageQueue::get_queue_type() const{
        return queueType;
    }


    Package PackageQueue::pop(){
        switch(queueType){
            case FIFO:
                return Package();


            case LIFO:
                return Package();

            default:
                return Package();

        }
    }

    PackageQueue::~PackageQueue() = default;













