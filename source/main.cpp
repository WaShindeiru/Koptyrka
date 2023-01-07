#include <iostream>
#include "storage_types.hpp"
#include "package.hpp"

int main() {
    Package package = Package();
    Package package2 = Package();

    std::cout << package.get_id();
    std::cout << package2.get_id();

    return 0;
}
