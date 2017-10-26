///////////////////////////
// Tanner Kvarfordt      //
// A02052217             //
// CS 3100 --Dr. Mathias //
// Assignment 5          //
///////////////////////////

#ifndef _SYNCED_HASH_TABLE
#define _SYNCED_HASH_TABLE

#include <mutex>
#include <unordered_map>

// This class provides a thread-safe version of a std::unordered_map
//
// Note that this class cannot be passed by const reference or copied due to its
// private std::mutex member, m_mutex
//
// This class does not provide the following functionality that is provided by a std::unordered map:
//       - TODO: fill out this list
//       - 
template<typename Key, typename T>
class SyncedHashTable {
public:

    // ----------------------------- CONSTRUCTORS ---------------------------------------- //

    SyncedHashTable() : m_table(), m_mutex() {}

    // TODO: provide additional appropriate constructors

    // ------------------------ PUBLIC MEMBER FUNCTIONS ---------------------------------- //

    // Returns true if the Table is empty
    // Returns fals if the Table is not empty
    bool empty() {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_table.empty();
    }

    // Returns the number of items in the Table
    uint64_t size() {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_table.size();
    }

    // Returns a reference to the mapped value of the element with a key equivalent to k
    T& at(Key const & k) {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_table.at(k);
    }

    // Returns a reference to the mapped value of the element with a key equivalent to k if one exists
    // If k does not match the key of any element in the container, the function inserts a new element
    // with that key and returns a reference to its mapped value which will increase container size by 1
    // The element at k is constructed with its default constructor
    T& operator[](Key const & k) {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_table[k];
    }



    // Returns a copy of the underlying std::unordered_map
    // The returned unordered_map is NOT thread safe
    std::unordered_map<Key, T> getUnorderedMap() { 
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_table; 
    }

private:

    // ------------------------ VARIABLES AND CONSTANTS ---------------------------------- //
    
    std::unordered_map<Key, T> m_table;

    std::mutex m_mutex;

    // ------------------------ PRIVATE MEMBER FUNCTIONS ---------------------------------- //

};

#endif
