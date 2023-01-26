#include <algorithm>
#include "package.hpp"
#include "types.hpp"
#include "storage_types.hpp"

std::vector<ElementID> Package::usedlist = {0};
std::vector<ElementID> Package::freelist = {};

Package::Package(){
    if(freelist.empty()){
        auto maxiter = std::max_element(usedlist.begin(), usedlist.end());
        ID_=*maxiter+1;
        usedlist.push_back(ID_);
    }
    else{
        auto miniter = std::min_element(freelist.begin(), freelist.end());
        ID_=*miniter;
        freelist.erase(miniter);
        usedlist.push_back(ID_);
    }
}

Package::Package(const ElementID id){
    auto id_usediter = std::find(usedlist.begin(), usedlist.end(), id);
    if (id_usediter == usedlist.end()) {
        ID_ = id;
        usedlist.push_back(ID_);
        auto id_freeiter = std::find(freelist.begin(), freelist.end(), id);
        if (id_freeiter != freelist.end())
            freelist.erase(id_freeiter);
    }
    else {
        ID_ = 0;
    }
}

Package::Package(Package&& old) noexcept{
    ID_= old.ID_;
    old.ID_ = 0;
}

Package& Package::operator = (Package&& rvalue) noexcept{
    if (ID_!=0 && ID_!=rvalue.ID_) {
        auto id_usediter = std::find(usedlist.begin(), usedlist.end(), ID_);
        usedlist.erase(id_usediter);
        freelist.push_back(ID_);
    }
    ID_ = rvalue.ID_;
    rvalue.ID_ = 0;
    return *this;
}

Package::~Package(){
    if (ID_!=0) {
        auto id_usediter = std::find(usedlist.begin(), usedlist.end(), ID_);
        usedlist.erase(id_usediter);
        freelist.push_back(ID_);
    }
}