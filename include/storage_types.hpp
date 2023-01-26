#ifndef NETSIM_STORAGE_TYPES_HPP
#define NETSIM_STORAGE_TYPES_HPP

#include "types.hpp"
#include "package.hpp"
#include <iostream>
#include <list>

enum class PackageQueueType{
    FIFO,
    LIFO
};

class IPackageStockpile{
public:
    virtual void push(Package&&) = 0;
    virtual bool empty() = 0;
    virtual size_t size() = 0;
    using const_iterator = std::list<Package>::const_iterator;
    virtual const_iterator begin() = 0;
    virtual const_iterator end() = 0;
    virtual ~IPackageStockpile() = default;
};

class IPackageQueue : public IPackageStockpile{
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() = 0;
    virtual ~IPackageQueue() = default;
};

class PackageQueue : public IPackageQueue{
public:
    explicit PackageQueue(PackageQueueType x) : queueType(x) {};
    const_iterator begin() override { return packageList.begin(); }
    const_iterator end() override { return packageList.end(); }
    void push(Package&& product) override {packageList.emplace_back(Package(std::move(product)));};
    bool empty() override {return (packageList.empty());};
    size_t size() override {return (packageList.size());};
    Package pop() override;
    PackageQueueType get_queue_type() override {return queueType;};
    ~PackageQueue() override = default;
private:
    PackageQueueType queueType;
    std::list<Package> packageList;
};

#endif
