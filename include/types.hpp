//
// Created by frane on 07/01/2023.
//
#import <stdlib.h>

#ifndef KOT_TYPES_HPP
#define KOT_TYPES_HPP

using ElementID = std::size_t;

enum class PackageQueueType {
    FIFO,
    LIFO,
};

#endif //KOT_TYPES_HPP
