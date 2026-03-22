// e_hashtable_large.cpp - EHashTable large functions (257-1024 bytes)
// Object file: base_ngc_release_dvd.lib(e_hashtable.obj)
// Section at 0x802C88C4, size 0x089C
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"

extern "C" void* EAHeap_Alloc(int size);
extern "C" void EAHeap_Free2(void* ptr);

// EHashTable - hash table implementation using chained buckets
// Layout from disassembly:
// 0x00 = bucket array pointer
// 0x04 = num buckets
// 0x08 = num entries
// 0x0C = hash function pointer
// 0x10 = compare function pointer
// 0x14 = flags

struct EHashTableEntry {
    u32 m_key;                   // 0x00
    u32 m_value;                 // 0x04
    EHashTableEntry* m_next;     // 0x08
};

struct EHashTable {
    EHashTableEntry** m_buckets; // 0x00
    u32 m_numBuckets;            // 0x04
    u32 m_numEntries;            // 0x08
    void* m_hashFn;              // 0x0C
    void* m_compareFn;           // 0x10
    u32 m_flags;                 // 0x14

    void Init(u32 numBuckets, void* hashFn, void* compareFn);
    void Shutdown();
    void* Find(u32 key);
    void Insert(u32 key, u32 value);
    void Remove(u32 key);
    void Resize(u32 newSize);
    void Clear();
};

// ============================================================================
// EHashTable::Init
// NON_MATCHING - initializes hash table with given bucket count
// Size: ~280 bytes
// ============================================================================
void EHashTable::Init(u32 numBuckets, void* hashFn, void* compareFn)
{
    m_numBuckets = numBuckets;
    m_numEntries = 0;
    m_hashFn = hashFn;
    m_compareFn = compareFn;
    m_flags = 0;

    // Allocate bucket array
    m_buckets = (EHashTableEntry**)EAHeap_Alloc(numBuckets * 4);
    if (m_buckets) {
        for (u32 i = 0; i < numBuckets; i++) {
            m_buckets[i] = 0;
        }
    }
}

// ============================================================================
// EHashTable::Shutdown
// NON_MATCHING - frees all entries and buckets
// Size: ~300 bytes
// ============================================================================
void EHashTable::Shutdown()
{
    // Free all entries
    if (m_buckets) {
        for (u32 i = 0; i < m_numBuckets; i++) {
            EHashTableEntry* entry = m_buckets[i];
            while (entry) {
                EHashTableEntry* next = entry->m_next;
                EAHeap_Free2(entry);
                entry = next;
            }
        }
        EAHeap_Free2(m_buckets);
        m_buckets = 0;
    }
    m_numBuckets = 0;
    m_numEntries = 0;
}

// ============================================================================
// EHashTable::Find
// NON_MATCHING - looks up value by key
// Size: ~300 bytes
// ============================================================================
void* EHashTable::Find(u32 key)
{
    if (!m_buckets || m_numBuckets == 0) return 0;

    // Hash the key
    typedef u32 (*HashFn)(u32);
    u32 hash = ((HashFn)m_hashFn)(key);
    u32 bucket = hash % m_numBuckets;

    // Search chain
    EHashTableEntry* entry = m_buckets[bucket];
    while (entry) {
        typedef int (*CompareFn)(u32, u32);
        if (((CompareFn)m_compareFn)(entry->m_key, key) == 0) {
            return (void*)entry->m_value;
        }
        entry = entry->m_next;
    }

    return 0;
}

// ============================================================================
// EHashTable::Insert
// NON_MATCHING - inserts key-value pair
// Size: ~350 bytes
// ============================================================================
void EHashTable::Insert(u32 key, u32 value)
{
    if (!m_buckets) return;

    typedef u32 (*HashFn)(u32);
    u32 hash = ((HashFn)m_hashFn)(key);
    u32 bucket = hash % m_numBuckets;

    // Check for existing entry
    EHashTableEntry* entry = m_buckets[bucket];
    while (entry) {
        typedef int (*CompareFn)(u32, u32);
        if (((CompareFn)m_compareFn)(entry->m_key, key) == 0) {
            // Update existing
            entry->m_value = value;
            return;
        }
        entry = entry->m_next;
    }

    // Allocate new entry
    EHashTableEntry* newEntry = (EHashTableEntry*)EAHeap_Alloc(12);
    if (!newEntry) return;

    newEntry->m_key = key;
    newEntry->m_value = value;
    newEntry->m_next = m_buckets[bucket];
    m_buckets[bucket] = newEntry;
    m_numEntries++;

    // Check load factor, resize if needed
    if (m_numEntries > m_numBuckets * 2) {
        Resize(m_numBuckets * 2);
    }
}

// ============================================================================
// EHashTable::Remove
// NON_MATCHING - removes entry by key
// Size: ~300 bytes
// ============================================================================
void EHashTable::Remove(u32 key)
{
    if (!m_buckets) return;

    typedef u32 (*HashFn)(u32);
    u32 hash = ((HashFn)m_hashFn)(key);
    u32 bucket = hash % m_numBuckets;

    EHashTableEntry** prev = &m_buckets[bucket];
    EHashTableEntry* entry = *prev;

    while (entry) {
        typedef int (*CompareFn)(u32, u32);
        if (((CompareFn)m_compareFn)(entry->m_key, key) == 0) {
            *prev = entry->m_next;
            EAHeap_Free2(entry);
            m_numEntries--;
            return;
        }
        prev = &entry->m_next;
        entry = entry->m_next;
    }
}

// ============================================================================
// EHashTable::Resize
// NON_MATCHING - resizes the hash table
// Size: ~400 bytes
// ============================================================================
void EHashTable::Resize(u32 newSize)
{
    if (newSize == 0) return;

    // Allocate new bucket array
    EHashTableEntry** newBuckets = (EHashTableEntry**)EAHeap_Alloc(newSize * 4);
    if (!newBuckets) return;

    for (u32 i = 0; i < newSize; i++) {
        newBuckets[i] = 0;
    }

    // Rehash all entries
    typedef u32 (*HashFn)(u32);
    for (u32 i = 0; i < m_numBuckets; i++) {
        EHashTableEntry* entry = m_buckets[i];
        while (entry) {
            EHashTableEntry* next = entry->m_next;

            u32 hash = ((HashFn)m_hashFn)(entry->m_key);
            u32 newBucket = hash % newSize;

            entry->m_next = newBuckets[newBucket];
            newBuckets[newBucket] = entry;

            entry = next;
        }
    }

    // Free old buckets
    EAHeap_Free2(m_buckets);
    m_buckets = newBuckets;
    m_numBuckets = newSize;
}

// ============================================================================
// EHashTable::Clear
// NON_MATCHING - removes all entries without freeing bucket array
// Size: ~260 bytes
// ============================================================================
void EHashTable::Clear()
{
    if (!m_buckets) return;

    for (u32 i = 0; i < m_numBuckets; i++) {
        EHashTableEntry* entry = m_buckets[i];
        while (entry) {
            EHashTableEntry* next = entry->m_next;
            EAHeap_Free2(entry);
            entry = next;
        }
        m_buckets[i] = 0;
    }
    m_numEntries = 0;
}
