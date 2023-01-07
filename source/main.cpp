#include <iostream>
#include "storage_types.hpp"
#include "package.hpp"

int main() {
    Package package = Package();
    Package package2 = Package();

    PackageQueue queue = PackageQueue(LIFO);

    std::cout << package.get_id() << '\n';
    std::cout << package2.get_id();

    return 0;
}
