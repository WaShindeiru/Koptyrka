#ifndef NETSIM_NODES_HPP
#define NETSIM_NODES_HPP

#include <map>
#include <memory>
#include <utility>
#include "storage_types.hpp"
#include "types.hpp"
#include "helpers.hpp"

enum class ReceiverType{
    RAMP,
    WORKER,
    STOREHOUSE
};

class IPackageReceiver{
public:
    using const_iterator = IPackageStockpile::const_iterator;
    virtual void receive_package(Package&& p)=0;
    ElementID get_id() const {return id;};
    virtual ~IPackageReceiver() = default;
protected:
    ElementID id;
};

class Storehouse : public IPackageReceiver{
public:
    const_iterator begin() { return iPtrStockpile->begin(); }
    const_iterator end() { return iPtrStockpile->end(); }
    const_iterator cbegin() { return iPtrStockpile->begin(); }
    const_iterator cend() { return iPtrStockpile->end(); }
    explicit Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d = std::make_unique<PackageQueue>(PackageQueueType::FIFO));
    void receive_package(Package &&p) override;
private:
    std::unique_ptr<IPackageStockpile> iPtrStockpile;
};

class ReceiverPreferences{
public:
    using preferences_t = std::map<IPackageReceiver*, double>;
    using const_iterator = preferences_t::const_iterator;

    const_iterator begin() { return preferences.begin(); }
    const_iterator end() { return preferences.end(); }
    const_iterator cbegin() { return preferences.begin(); }
    const_iterator cend() { return preferences.end(); }

    preferences_t preferences;
    ProbabilityGenerator generator;

    explicit ReceiverPreferences(ProbabilityGenerator pb = probability_generator) : generator(std::move(pb)) {};
    void add_receiver(IPackageReceiver* r);
    void remove_receiver(IPackageReceiver* r);
    IPackageReceiver* choose_receiver();
    preferences_t& get_preferences() {return preferences;};
};

class PackageSender{
public:
    ReceiverPreferences receiver_preferences_;
    PackageSender() : packageBuffer(std::nullopt){};
    PackageSender(PackageSender&&) = default;
    void send_package();
    std::optional<Package>& get_sending_buffer() {return packageBuffer;};
protected:
    void push_package(Package&& product) { packageBuffer = Package(std::move(product));};
    std::optional<Package> packageBuffer;
};

class Ramp : public PackageSender{
public:
    Ramp(ElementID id, TimeOffset di) : id(id), timeOffset(di) {};
    void deliver_goods(Time t);
    TimeOffset get_delivery_interval() const {return timeOffset;};
    ElementID get_id() const {return id;};
private:
    ElementID id;
    TimeOffset timeOffset;
};

class Worker : public PackageSender, public IPackageReceiver{
public:
    const_iterator begin() { return iPtr->begin(); }
    const_iterator end() { return iPtr->end(); }
    const_iterator cbegin() { return iPtr->begin(); }
    const_iterator cend() { return iPtr->end(); }
    Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q);
    void do_work(Time t);
    TimeOffset get_processing_duration() const {return timeOffset;};
    Time get_package_processing_start_time() const {return startTime;};
    void receive_package(Package&& p) override;
private:
    TimeOffset timeOffset;
    Time startTime=1;
    std::unique_ptr<IPackageQueue> iPtr;
};
#endif

