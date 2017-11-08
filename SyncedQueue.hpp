///////////////////////////
// Tanner Kvarfordt      //
// A02052217             //
// CS 3100 --Dr. Mathias //
// Assignment 5          //
///////////////////////////

#ifndef _SYNCED_QUEUE_HPP
#define _SYNCED_QUEUE_HPP

#include <mutex>
#include <queue>
#include <memory>

// This class provides a thread-safe version of a std::queue
//
// Note that this class cannot be passed by const reference or copied due to its 
// private std::mutex member, m_mutex
// 
// This is a first-in, first-out data structure
// 
// This class does not provide the emplace or swap functionality provided by std::queue
template<typename T>
class SyncedQueue {
public:

    // ----------------------------- CONSTRUCTORS ---------------------------------------- //

    SyncedQueue() : m_queue(), m_mutex() {}

    SyncedQueue(std::queue<T> const & q) : m_queue(q), m_mutex() {}

    // No copy construction allowed
    SyncedQueue(SyncedQueue const&) = delete;

    // ------------------------ PUBLIC MEMBER FUNCTIONS ---------------------------------- //

    // No copy assignment allowed
    SyncedQueue& operator=(SyncedQueue const&) = delete;

    // Returns true if the queue is empty
    // Returns false if the queue is not empty
    bool empty() {
        std::lock_guard<std::mutex> lock(this->m_mutex);
        return m_queue.empty();
    }

    // Returns the number of items in the queue
    uint64_t size() {
        std::lock_guard<std::mutex> lock(this->m_mutex);
        return m_queue.size();
    }

    // Returns, but does not remove, the next item in the queue
    T front() {
        std::lock_guard<std::mutex> lock(this->m_mutex);
        return m_queue.front();
    }

    // Returns, but does not remove, the last item in the queue
    T back() {
        std::lock_guard<std::mutex> lock(this->m_mutex);
        return m_queue.back();
    }

    // Inserts @item to the back of the queue
    void push(T const & item) {
        std::lock_guard<std::mutex> lock(this->m_mutex);
        m_queue.push(item);
    }

    // Removes and returns a pointer to the next item in the queue
    // Returns nullptr if the queue is empty
    // Note that this differs from the std::queue implementation of pop, 
    // which does not return the popped item
    std::shared_ptr<T> pop() {
        std::lock_guard<std::mutex> lock(this->m_mutex);
        if (m_queue.empty()) return nullptr;
        std::shared_ptr<T> popped_item = std::make_shared<T>(m_queue.front());
        m_queue.pop();
        return popped_item;
    }

    // Returns a copy of the underlying std::queue
    // The returned queue is NOT thread safe
    std::queue<T> getQueue() { 
        std::lock_guard<std::mutex> lock(this->m_mutex);
        return m_queue; 
    }

private:

    // ------------------------ VARIABLES AND CONSTANTS ---------------------------------- //

    std::queue<T> m_queue;

    std::mutex m_mutex;

    // ------------------------ PRIVATE MEMBER FUNCTIONS ---------------------------------- //

};

#endif
