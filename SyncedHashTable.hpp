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
// All public member functions that access the underlying std::unordered_map require a std::mutex
// to provide the thread-safe functionality
//
// This class does not provide the following functionality that is provided by a std::unordered map:
//       - TODO: fill out this list
//       - 
template<typename Key, typename T>
class SyncedHashTable {
public:

    // ----------------------------- CONSTRUCTORS ---------------------------------------- //

    SyncedHashTable() : m_table() {}

    // TODO: provide additional appropriate constructors

    // ------------------------ PUBLIC MEMBER FUNCTIONS ---------------------------------- //

    // TODO: provide all necessary thread-safe member functions

    // Returns a copy of the underlying std::unordered_map
    // The returned unordered_map is NOT thread safe
    std::unordered_map<Key, T> getUnorderedMap(std::mutex & m) const { 
        std::lock_guard<std::mutex> lock(m);
        return m_table; 
    }

private:

    // ------------------------ VARIABLES AND CONSTANTS ---------------------------------- //
    
    std::unordered_map<Key, T> m_table;

    // ------------------------ PRIVATE MEMBER FUNCTIONS ---------------------------------- //

};

#endif
