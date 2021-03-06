///////////////////////////
// Tanner Kvarfordt      //
// A02052217             //
// CS 3100 --Dr. Mathias //
// Assignment 5          //
///////////////////////////


#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <functional>

#include "SyncedQueue.hpp"
#include "SyncedHashTable.hpp"
#include "PiComputer.hpp"

// The unsigned integral type that will be used to store integers up to the value of N_DIGITS 
// Can be changed to uint64_t or uint128_t if you wish to compute an insane number of pi digits
using _uint_ = uint32_t;

// The number of digits of pi to compute
const _uint_ N_DIGITS = 1000;

// Populates the SyncedQueue with the tasks (digits) of pi that need computing
void populateQueue(SyncedQueue<_uint_> & queue) {
    for (_uint_ i = 1; i <= N_DIGITS; ++i) {
        queue.push(i);
    }
}

void outputPi(SyncedHashTable<_uint_, uint16_t> & pi_digits) {
    std::cout << std::endl << "3.";
    for (_uint_ i = 1; i <= N_DIGITS; ++i) {
        std::cout << pi_digits.find(i)->second;
    }
}

void threadStart(SyncedQueue<_uint_> & queue, SyncedHashTable<_uint_, uint16_t> & pi_digits) {
    std::shared_ptr<_uint_> digit_pos;
    while ((digit_pos = queue.pop()) != nullptr) {
        // indicate progress
        std::cout << ".";
        std::cout.flush();
        auto digit = computePiDigit(*digit_pos);
        pi_digits.insert(*digit_pos, digit);
        digit_pos.reset();
    }
}

int main() {
    SyncedQueue<_uint_> queue;
    populateQueue(queue);

    // Key-value pair hashtable where:
    // Key is a _uint_ to indicate the nth digit of pi
    // Value is the digit of pi in that position
    SyncedHashTable<_uint_, uint16_t> pi_digits;

    std::vector<std::thread> threads;
    for (uint16_t i = 0; i < std::thread::hardware_concurrency(); ++i) {
        threads.push_back(std::thread(threadStart, std::ref(queue), std::ref(pi_digits)));
    }

    for (auto && th : threads) th.join();

    outputPi(pi_digits);

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
