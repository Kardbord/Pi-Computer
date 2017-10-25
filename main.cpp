///////////////////////////
// Tanner Kvarfordt      //
// A02052217             //
// CS 3100 --Dr. Mathias //
// Assignment 5          //
///////////////////////////


#include <iostream>
#include <cstdlib>

#include <mutex>
#include "SyncedQueue.hpp"

int main() {
    std::mutex m;

    // ---------- SyncedQueue Default Constructor Test ---------- //
    std::cout << "SyncedQueue 1:" << std::endl;
    SyncedQueue<int> q;
    for (int i = 0; i < 10; ++i) q.push(i, m);

    if (!q.empty(m)) { 
        std::cout << "front: " << q.front(m) << std::endl;
        std::cout << "back: " << q.back(m) << std::endl;
    }
    std::cout << "size: " << q.size(m) << std::endl;
    std::cout << "popped: " << q.pop(m) << std::endl;
    std::cout << "popped: " << q.pop(m) << std::endl;

    // ---------- SyncedQueue Pure Copy Constructor Test ---------- //
    std::cout << std::endl;
    std::cout << "SyncedQueue 2:" << std::endl;
    SyncedQueue<int> q2(q);
    if (!q2.empty(m)) { 
        std::cout << "front: " << q2.front(m) << std::endl;
        std::cout << "back: " << q2.back(m) << std::endl;
    }
    std::cout << "size: " << q2.size(m) << std::endl;
    std::cout << "popped: " << q2.pop(m) << std::endl;
    std::cout << "popped: " << q2.pop(m) << std::endl;

    // ---------- SyncedQueue Queue Copy Constructor Test ---------- //
    std::cout << std::endl;
    std::queue<int> stdq(q2.getQueue());
    std::cout << "SyncedQueue 3:" << std::endl;
    SyncedQueue<int> q3(stdq);
    if (!q3.empty(m)) { 
        std::cout << "front: " << q3.front(m) << std::endl;
        std::cout << "back: " << q3.back(m) << std::endl;
    }
    std::cout << "size: " << q3.size(m) << std::endl;
    std::cout << "popped: " << q3.pop(m) << std::endl;
    std::cout << "popped: " << q3.pop(m) << std::endl;

    return EXIT_SUCCESS;
}
