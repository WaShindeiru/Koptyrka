#include <optional>
#include "nodes.hpp"
#include "storage_types.hpp"
#include "package.hpp"
#include "helpers.hpp"


void PackageSender::send_package(){
    if(packageBuffer != std::nullopt){
        if (receiver_preferences_.get_preferences().empty())
            std::cout<<"Brak odbiorcy"<<std::endl;
        else{
            Package Package_to_send = Package(std::move(packageBuffer.value()));
            packageBuffer = std::nullopt;
            receiver_preferences_.choose_receiver()->receive_package(std::move(Package_to_send));
        }
    }
}

IPackageReceiver* ReceiverPreferences::choose_receiver() {
    double pb = generator();
    auto iterator = preferences.begin();
    auto end_it = preferences.end();
    end_it--;
    double lowerScope = 0;
    double higherScope = iterator->second;
    while(iterator!=end_it){
        if (pb >= lowerScope and pb < higherScope) {
            break;
        }
        lowerScope=higherScope;
        iterator++;
        higherScope+=iterator->second;
    }
    return iterator->first;
}

void ReceiverPreferences::add_receiver(IPackageReceiver *r) {
    if (preferences.find(r) == preferences.end()) {
        double new_receiver_p = 1;
        double all_p_divisor = 1 + new_receiver_p;
        if (preferences.empty())
            all_p_divisor = new_receiver_p;
        preferences.insert(std::pair<IPackageReceiver *, double>(r, new_receiver_p));
        for (auto &preference : preferences) {
            preference.second = preference.second / all_p_divisor;
        }
    }
}

void ReceiverPreferences::remove_receiver(IPackageReceiver *r) {
    if (preferences.find(r) != preferences.end()) {
        double all_p_divisor =
                1 - preferences[r];
        preferences.erase(r);
        for (auto &preference : preferences) {
            preference.second = preference.second / all_p_divisor;
        }
    }
}

void Ramp::deliver_goods(Time t) {
    if ((double(t-1)/double(timeOffset) == floor(double(t - 1) / double(timeOffset))) or t == 1) {
        push_package(Package());
    }
}

void Storehouse::receive_package(Package &&p) {
    iPtrStockpile->push(std::move(p));
}

void Worker::receive_package(Package &&p) {
    if(get_sending_buffer().has_value())
        iPtr->push(std::move(p));
    else
        push_package(std::move(p));
}

void Worker::do_work(Time t) {
    if (startTime + timeOffset == t){
        startTime = t;
        send_package();
        if(not(iPtr->empty()))
            push_package(iPtr->pop());
    }
}

Worker::Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q) {
    id = id;
    timeOffset=pd;
    iPtr=std::move(q);
}

Storehouse::Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d) {
    id = id;
    iPtrStockpile = std::move(d);

}
