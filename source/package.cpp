#include "types.hpp"
#include <set>

class Package {
public:
    Package(){
        if (freed_IDs.empty()) {
            ID = assigned_IDs.size() + 1;
            assigned_IDs.insert(ID);
        } else {
            ID = *freed_IDs.begin();
            freed_IDs.erase(ID);
        }
    };

    Package(ElementID Id){
        ID = Id;
        assigned_IDs.insert(ID);
    };

    Package(Package&& other){
        ID = other.ID;
    }

    Package& operator=(Package&& other){
        ID = other.ID;
        return *this;

    };

    ElementID get_id() const{
        return ID;
    };

    ~Package(){
        freed_IDs.insert(ID);
        assigned_IDs.erase(ID);
    };

private:
    static std::set<ElementID> assigned_IDs;
    static std::set<ElementID> freed_IDs;
    ElementID ID;
};
