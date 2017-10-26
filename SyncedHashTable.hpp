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

    // TODO: provide additional appropriate constructors and prevent copy construction

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

    // Searches the container for an element with a key equivalent to k
    // Returns an iterator to that element if found, returns unordered_map::end otherwise
    typename std::unordered_map<Key, T>::const_iterator find(Key const & k) {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_table.find(k);
    }

    // Inserts a new element in the container
    // Each element is inserted only if its key is not equivalent to the key of 
    // any other element already in the container since keys in an unordered_map are unique
    //
    // Returns a pair where the first element in the pair is an iterator to the inserted element or to the 
    // element whose key is equivalent
    // The second element in the pair is a bool indicating whether or not the element was successfully inserted
    std::pair<typename std::unordered_map<Key, T>::const_iterator, bool> insert(std::pair<Key, T> const & item) {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_table.insert(item);
    }

    // Inserts a new element in the container
    // Each element is inserted only if its key is not equivalent to the key of 
    // any other element already in the container since keys in an unordered_map are unique
    //
    // Returns a pair where the first element in the pair is an iterator to the inserted element or to the 
    // element whose key is equivalent
    // The second element in the pair is a bool indicating whether or not the element was successfully inserted
    std::pair<typename std::unordered_map<Key, T>::const_iterator, bool> insert(Key const & k, T const & val) {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_table.insert(std::make_pair<Key, T>(k, val));
    }

    // Removes the element in the container whose key is equivalent to k
    void erase(Key const & k) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_table.erase(k);
    }

    // Removes the element in the container pointed at by @it
    void erase(typename std::unordered_map<Key, T>::const_iterator it) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_table.erase(it);
    }

    // All elements in the container are dropped: their destructors are called
    // The container is left with size 0
    void clear() {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_table.clear();
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
