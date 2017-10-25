#ifndef _SYNCED_QUEUE_HPP
#define _SYNCED_QUEUE_HPP

#include <mutex>
#include <queue>

// This class provides a thread-safe version of a std::queue
// All public member functions that access the underlying std::queue require a std::mutex
// to provide the thread-safe functionality.
// 
// This is a first-in, first-out data structure
// 
// This class does not provide the emplace or swap functionality provided by std::queue
template<typename T>
class SyncedQueue {
public:

    // ----------------------------- CONSTRUCTORS ---------------------------------------- //

    SyncedQueue() : m_queue() {}

    SyncedQueue(std::queue<T> const & q) : m_queue(q) {}

    SyncedQueue(SyncedQueue<T> const & q) : m_queue(q.getQueue()) {}

    // ------------------------ PUBLIC MEMBER FUNCTIONS ---------------------------------- //

    // Returns true if the queue is empty
    // Returns false if the queue is not empty
    bool empty(std::mutex & m) const {
        std::lock_guard<std::mutex> lock(m);
        return m_queue.empty();
    }

    // Returns the number of items in the queue
    uint32_t size(std::mutex & m) const {
        std::lock_guard<std::mutex> lock(m);
        return m_queue.size();
    }

    // Returns, but does not remove, the next item in the queue
    T front(std::mutex & m) const {
        std::lock_guard<std::mutex> lock(m);
        return m_queue.front();
    }

    // Returns, but does not remove, the last item in the queue
    T back(std::mutex & m) const {
        std::lock_guard<std::mutex> lock(m);
        return m_queue.back();
    }

    // Inserts @item to the back of the queue
    void push(T const & item, std::mutex & m) {
        std::lock_guard<std::mutex> lock(m);
        m_queue.push(item);
    }

    // Removes and returns the next item in the queue
    // Note that this differs from the std::queue implementation of pop, 
    // which does not return the popped item
    T pop(std::mutex & m) {
        std::lock_guard<std::mutex> lock(m);
        T popped_item = m_queue.front();
        m_queue.pop();
        return popped_item;
    }

    // Returns a copy of the underlying std::queue
    // The returned queue is NOT thread safe
    std::queue<T> getQueue() const { return m_queue; }

private:

    // ------------------------ VARIABLES AND CONSTANTS ---------------------------------- //

    std::queue<T> m_queue;

    // ------------------------ PRIVATE MEMBER FUNCTIONS ---------------------------------- //

};

#endif
