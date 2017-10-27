///////////////////////////
// Tanner Kvarfordt      //
// A02052217             //
// CS 3100 --Dr. Mathias //
// Assignment 5          //
///////////////////////////


#include <iostream>
#include <cstdlib>

#include "SyncedQueue.hpp"
#include "SyncedHashTable.hpp"
#include "PiComputer.hpp"

// The unsigned integral type that will be used to store integers up to the value of N_DIGITS 
// Can be changed to uint64_t or uint128_t if you wish to compute an insane number of pi digits
using _uint_ = uint32_t;

// The number of digits of pi to compute
const _uint_ N_DIGITS = 1000;

// Populates the SyncedQueue with the tasks (digits) of pi that need computing
template<typename T = _uint_>
void populateQueue(SyncedQueue<T> & queue) {
    for (_uint_ i = 1; i < N_DIGITS; ++i) {
        queue.push(i);
    }
}

int main() {
    SyncedQueue<_uint_> queue;
    populateQueue(queue);

    std::cout << queue.pop() << std::endl << queue.pop() << std::endl;

    return EXIT_SUCCESS;
}
