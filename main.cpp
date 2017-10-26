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

int main() {
    // ---------- SyncedQueue Default Constructor Test ---------- //
    std::cout << "SyncedQueue 1:" << std::endl;
    SyncedQueue<int> q;
    for (int i = 0; i < 10; ++i) q.push(i);

    if (!q.empty()) { 
        std::cout << "front: " << q.front() << std::endl;
        std::cout << "back: " << q.back() << std::endl;
    }
    std::cout << "size: " << q.size() << std::endl;
    std::cout << "popped: " << q.pop() << std::endl;
    std::cout << "popped: " << q.pop() << std::endl;

    // ---------- SyncedQueue Pure Copy Constructor Test ---------- //
    std::cout << std::endl;
    std::cout << "SyncedQueue 2:" << std::endl;
    SyncedQueue<int> q2(q.getQueue());
    if (!q2.empty()) { 
        std::cout << "front: " << q2.front() << std::endl;
        std::cout << "back: " << q2.back() << std::endl;
    }
    std::cout << "size: " << q2.size() << std::endl;
    std::cout << "popped: " << q2.pop() << std::endl;
    std::cout << "popped: " << q2.pop() << std::endl;

    return EXIT_SUCCESS;
}
