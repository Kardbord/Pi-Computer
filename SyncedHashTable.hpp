#ifndef _SYNCED_HASH_TABLE
#define _SYNCED_HASH_TABLE

#include <mutex>
#include <unordered_map>

template<typename Key, typename T>
class SyncedHashTable {
public:

    // ----------------------------- CONSTRUCTORS ---------------------------------------- //

    SyncedHashTable() : m_table() {}

    // ------------------------ PUBLIC MEMBER FUNCTIONS ---------------------------------- //

private:

    // ------------------------ VARIABLES AND CONSTANTS ---------------------------------- //
    
    std::unordered_map<Key, T> m_table;

    // ------------------------ PRIVATE MEMBER FUNCTIONS ---------------------------------- //

};

#endif
