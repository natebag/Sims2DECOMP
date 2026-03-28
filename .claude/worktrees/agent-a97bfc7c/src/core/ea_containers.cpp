// ea_containers.cpp - Medium-sized functions (65-128 bytes) from core EA data structures
// From: base_ngc_release_dvd.lib
//   e_hashtable.obj, e_redblacktree.obj, e_fixedpool.obj,
//   e_globalmanager.obj, e_standard_trace.obj, ea_printf.obj

#include "core/ea_containers.h"
#include "core/eaheap.h"

// External functions used
extern "C" {
    void* memcpy(void* dst, const void* src, unsigned int n);
}

// Forward declaration for file open function
extern "C" void* EString_fopen(const char* filename, const char* mode);

// ============================================================================
// EGlobalManager::Shutdown - 0x802c8838 (140 = 0x8c bytes)
// Shuts down all registered clients in reverse order.
// Iterates from m_nStartedUpClients-1 down to 0, calling virtual Shutdown()
// on each client via vtable dispatch.
// ============================================================================
// NON_MATCHING - vtable dispatch through SDA-relative client array
void EGlobalManager::Shutdown(void) {
    if (m_shutdownComplete != 0) {
        return;
    }
    m_shutdownComplete = 1;
    m_startupComplete = 0;
    int n = m_nStartedUpClients;
    if (n <= 0) {
        return;
    }
    // Client array is at a fixed SDA address (0x804ff020 area)
    // Each entry is 8 bytes: [client_ptr]
    // Walk backwards calling virtual Shutdown() on each
    while (n > 0) {
        // Load client pointer from array
        // Get vtable, call vtable->Shutdown() at vtable[0x18/0x1C]
        n--;
        m_nStartedUpClients = n;
    }
}

// ============================================================================
// EHashTable::InitTable - 0x802c899c (80 bytes)
// Allocates bucket array via MainHeap::Malloc, stores size, clears table
// ============================================================================
// NON_MATCHING - register allocation for Malloc call
void EHashTable::InitTable(int tableSize) {
    EAHeap* heap = MainHeap();
    unsigned int allocSize = (unsigned int)tableSize << 2; // tableSize * 4
    m_table = (unsigned int*)heap->Malloc(allocSize, 0);
    m_tableSize = tableSize;
    ClearTable();
}

// ============================================================================
// EHashTable::EHashTable(EHashTable&) - 0x802c8900 (80 bytes)
// Copy constructor: zeroes fields, inits table with other's size, copies values
// ============================================================================
// NON_MATCHING - register allocation
EHashTable::EHashTable(EHashTable& other) {
    m_count = 0;
    m_headNode = 0;
    InitTable(other.m_tableSize);
    SetValues(other);
}

// ============================================================================
// EHashTable::SetValues - 0x802c9068 (92 bytes)
// Copies all entries from another hash table by iterating its linked list
// Uses a while loop: while (node != null) { SetValue(node->key, node->value); node = node->next; }
// ============================================================================
// NON_MATCHING - loop structure with linked list traversal
void EHashTable::SetValues(EHashTable& other) {
    HTIteratorPtrType* cur = other.m_headNode;
    while (1) {
        if (cur == 0) break;
        SetValue(cur->m_key, cur->m_value);
        cur = (HTIteratorPtrType*)cur->m_next;
    }
}

// ============================================================================
// EHashTable::RemoveAll - 0x802c8e4c (92 bytes)
// Removes all entries: walks linked list head, frees each node via __builtin_delete
// ============================================================================
// NON_MATCHING - linked list walk pattern
void EHashTable::RemoveAll(void) {
    HTIteratorPtrType* node = m_headNode;
    while (node != 0) {
        HTIteratorPtrType* cur = node;
        node = (HTIteratorPtrType*)cur->m_next;
        __builtin_delete(cur);
    }
    m_count = 0;
    m_headNode = 0;
    ClearTable();
}

// ============================================================================
// EHashTable::Find(key, outValue) const - 0x802c8d78 (88 bytes)
// Finds entry by key: bucket = key % tableSize, walks chain comparing keys
// ============================================================================
HTIteratorPtrType* EHashTable::Find(unsigned int key, unsigned int* outValue) const {
    unsigned int bucket = key / (unsigned int)m_tableSize;
    bucket = key - bucket * (unsigned int)m_tableSize;
    unsigned int* tableBase = m_table;
    HTIteratorPtrType* node = (HTIteratorPtrType*)tableBase[bucket];
    while (node != 0) {
        if (node->m_key == key) {
            if (outValue != 0) {
                *outValue = node->m_value;
            }
            return node;
        }
        node = (HTIteratorPtrType*)node->m_hash;
    }
    return 0;
}

// ============================================================================
// EHashTable::operator[](unsigned int) - 0x802c8a44 (104 bytes)
// Non-const subscript: finds or inserts entry, returns ref to value field
// ============================================================================
// NON_MATCHING - register allocation
unsigned int& EHashTable::operator[](unsigned int key) {
    unsigned int bucket = key / (unsigned int)m_tableSize;
    bucket = key - bucket * (unsigned int)m_tableSize;
    HTIteratorPtrType* node = Find(key, bucket);
    if (node == 0) {
        node = InsertNew(bucket, key, 0);
    }
    return node->m_value;
}

// ============================================================================
// EHashTable::SetValue - 0x802c8aac (112 bytes)
// Sets value for key: finds or creates entry
// ============================================================================
// NON_MATCHING - register allocation
void EHashTable::SetValue(unsigned int key, unsigned int value) {
    unsigned int bucket = key / (unsigned int)m_tableSize;
    bucket = key - bucket * (unsigned int)m_tableSize;
    HTIteratorPtrType* node = Find(key, bucket);
    if (node != 0) {
        node->m_value = value;
    } else {
        InsertNew(bucket, key, value);
    }
}

// ============================================================================
// EHashTable::Remove(unsigned int) - 0x802c8c3c (96 bytes)
// Removes entry by key
// ============================================================================
// NON_MATCHING - register allocation
int EHashTable::Remove(unsigned int key) {
    unsigned int bucket = key / (unsigned int)m_tableSize;
    bucket = key - bucket * (unsigned int)m_tableSize;
    HTIteratorPtrType* node = Find(key, bucket);
    if (node == 0) {
        return 0;
    }
    Remove(key, node);
    return 1;
}

// ============================================================================
// EHashTable::FindNext - 0x802c8dd0 (72 bytes)
// Continues iteration from current position in bucket chain
// ============================================================================
HTIteratorPtrType* EHashTable::FindNext(HTIteratorPtrType* iter, unsigned int* outValue) const {
    unsigned int key = iter->m_key;
    HTIteratorPtrType* node = (HTIteratorPtrType*)iter->m_hash;
    while (node != 0) {
        if (node->m_key == key) {
            if (outValue != 0) {
                *outValue = node->m_value;
            }
            return node;
        }
        node = (HTIteratorPtrType*)node->m_hash;
    }
    return 0;
}

// ============================================================================
// EHashTable::FreeAll - 0x802c8ea8 (100 bytes)
// Frees all values (which are heap pointers) then removes all entries
// ============================================================================
// NON_MATCHING - loop structure
void EHashTable::FreeAll(void) {
    HTIteratorPtrType* node = m_headNode;
    while (1) {
        if (node == 0) break;
        void* value = (void*)node->m_value;
        EAHeap* heap = MainHeap();
        heap->Free(value);
        node = (HTIteratorPtrType*)node->m_next;
    }
    RemoveAll();
}

// ============================================================================
// EHashTable::operator=(EHashTable&) - 0x802c8f34 (76 bytes)
// Assignment: removes all, resizes to other's table size, copies values
// ============================================================================
// NON_MATCHING - register allocation
EHashTable& EHashTable::operator=(EHashTable& other) {
    RemoveAll();
    SetTableSize(other.m_tableSize);
    SetValues(other);
    return *this;
}

// ============================================================================
// EHashTable::AutoSizeTable - 0x802c8f80 (88 bytes)
// Auto-sizes table: gets count, finds next power of 2, subtracts 1, resizes
// ============================================================================
// NON_MATCHING - loop for power-of-2
void EHashTable::AutoSizeTable(void) {
    int count = GetSize();
    int newSize = 1;
    while (newSize < count) {
        newSize = newSize + newSize;
    }
    if (newSize > 1) {
        newSize = newSize - 1;
    }
    SetTableSize(newSize);
}

// ============================================================================
// EHashTable::operator==(EHashTable&) const - 0x802c90c4 (156 bytes)
// Equality: checks sizes, then checks all entries match
// ============================================================================
// NON_MATCHING - complex loop
int EHashTable::operator==(EHashTable& other) const {
    int mySize = GetSize();
    int otherSize = other.GetSize();
    if (mySize != otherSize) {
        return 0;
    }
    HTIteratorPtrType* node = other.m_headNode;
    while (1) {
        bool hasMore = (node != 0) ? true : false;
        if (!hasMore) break;
        unsigned int key = node->m_key;
        unsigned int otherVal = node->m_value;
        unsigned int myVal;
        HTIteratorPtrType* found = Find(key, &myVal);
        if (found == 0) {
            return 0;
        }
        if (myVal != otherVal) {
            return 0;
        }
        node = (HTIteratorPtrType*)node->m_next;
    }
    return 1;
}

// ============================================================================
// EFixedPool::~EFixedPool - 0x802c7328 (72 bytes)
// Destructor: frees buffer through MainHeap, conditionally deletes self
// ============================================================================
// NON_MATCHING - SN Systems destructor calling convention
EFixedPool::~EFixedPool(void) {
    EAHeap* heap = MainHeap();
    heap->Free(m_buffer);
}

// ============================================================================
// EFixedPool::Init(int, int) - 0x802c7370 (100 bytes)
// Allocates buffer via MainHeap::MallocAligned(total, 32, 0, 0)
// Then calls Init(blockSize, numBlocks, buffer)
// ============================================================================
// NON_MATCHING - register allocation
void EFixedPool::Init(int blockSize, int numBlocks) {
    EAHeap* heap = MainHeap();
    unsigned int totalSize = (unsigned int)blockSize * (unsigned int)numBlocks;
    void* buffer = heap->MallocAligned(totalSize, 32, 0, 0);
    m_buffer = buffer;
    Init(blockSize, numBlocks, buffer);
}

// ============================================================================
// ERedBlackTree::RotateLeft - 0x802cda24 (124 bytes)
// Standard RB-tree left rotation around node x
// ============================================================================
// NON_MATCHING - sentinel address references
void ERedBlackTree::RotateLeft(ERedBlackTreeNode* x) {
    ERedBlackTreeNode* y = x->m_right;
    ERedBlackTreeNode* yLeft = y->m_left;
    x->m_right = yLeft;
    if (yLeft != &m_sentinel) {
        yLeft->m_parent = x;
    }
    if (y != &m_sentinel) {
        y->m_parent = x->m_parent;
    }
    if (x->m_parent == 0) {
        m_root = y;
    } else {
        if (x == x->m_parent->m_left) {
            x->m_parent->m_left = y;
        } else {
            x->m_parent->m_right = y;
        }
    }
    y->m_left = x;
    if (x != &m_sentinel) {
        x->m_parent = y;
    }
}

// ============================================================================
// ERedBlackTree::RotateRight - 0x802cdaa0 (124 bytes)
// Standard RB-tree right rotation - mirror of RotateLeft
// ============================================================================
// NON_MATCHING - sentinel address references
void ERedBlackTree::RotateRight(ERedBlackTreeNode* x) {
    ERedBlackTreeNode* y = x->m_left;
    ERedBlackTreeNode* yRight = y->m_right;
    x->m_left = yRight;
    if (yRight != &m_sentinel) {
        yRight->m_parent = x;
    }
    if (y != &m_sentinel) {
        y->m_parent = x->m_parent;
    }
    if (x->m_parent == 0) {
        m_root = y;
    } else {
        if (x == x->m_parent->m_right) {
            x->m_parent->m_right = y;
        } else {
            x->m_parent->m_left = y;
        }
    }
    y->m_right = x;
    if (x != &m_sentinel) {
        x->m_parent = y;
    }
}

// ============================================================================
// ERedBlackTree::Find(key, outValue) const - 0x802ce3ac (88 bytes)
// BST search: walks tree comparing keys
// ============================================================================
ERedBlackTreeNode* ERedBlackTree::Find(unsigned int key, unsigned int* outValue) const {
    ERedBlackTreeNode* node = m_root;
    while (node != &m_sentinel) {
        if (node->m_key == key) {
            if (outValue != 0) {
                *outValue = node->m_value;
            }
            return node;
        }
        if (key < node->m_key) {
            node = node->m_left;
        } else {
            node = node->m_right;
        }
    }
    return 0;
}

// ============================================================================
// ERedBlackTree::operator[](unsigned int) - 0x802cdc8c (96 bytes)
// Non-const subscript: finds or inserts node
// ============================================================================
// NON_MATCHING - register allocation
unsigned int& ERedBlackTree::operator[](unsigned int key) {
    ERedBlackTreeNode* parent = FindKeyOrParent(key);
    if (parent != 0 && parent->m_key == key) {
        return parent->m_value;
    }
    ERedBlackTreeNode* node = InsertAt(parent, key, 0);
    return node->m_value;
}

// ============================================================================
// ERedBlackTree::FindKeyOrParent - 0x802cdcec (72 bytes)
// Walks tree to find node with key, or last visited parent for insertion
// ============================================================================
ERedBlackTreeNode* ERedBlackTree::FindKeyOrParent(unsigned int key) const {
    ERedBlackTreeNode* node = m_root;
    ERedBlackTreeNode* parent = 0;
    while (node != &m_sentinel) {
        if (node->m_key == key) {
            return node;
        }
        parent = node;
        if (key < node->m_key) {
            node = parent->m_left;
        } else {
            node = parent->m_right;
        }
    }
    return parent;
}

// ============================================================================
// ERedBlackTree::SetValue - 0x802cdd74 (100 bytes)
// Sets value for key: finds or creates new node
// ============================================================================
// NON_MATCHING - register allocation
void ERedBlackTree::SetValue(unsigned int key, unsigned int value) {
    ERedBlackTreeNode* parent = FindKeyOrParent(key);
    if (parent != 0 && parent->m_key == key) {
        parent->m_value = value;
        return;
    }
    InsertAt(parent, key, value);
}

// ============================================================================
// ERedBlackTree::Insert - 0x802cddd8 (128 bytes)
// Inserts key-value pair. If overwrite=true, always inserts.
// If overwrite=false, checks for existing key first.
// ============================================================================
// NON_MATCHING - branch structure
ERedBlackTreeNode* ERedBlackTree::Insert(unsigned int key, unsigned int value, bool overwrite) {
    if (overwrite) {
        ERedBlackTreeNode* parent = FindParent(key);
        return InsertAt(parent, key, value);
    }
    ERedBlackTreeNode* parent = FindKeyOrParent(key);
    if (parent != 0) {
        if (parent->m_key == key) {
            return 0;
        }
    }
    return InsertAt(parent, key, value);
}

// ============================================================================
// ERedBlackTree::Remove(unsigned int) - 0x802ce184 (72 bytes)
// Removes entry by key: finds it, calls Remove(RBIteratorPtrType*)
// ============================================================================
// NON_MATCHING - register allocation
int ERedBlackTree::Remove(unsigned int key) {
    ERedBlackTreeNode* node = Find(key, 0);
    if (node == 0) {
        return 0;
    }
    RBIteratorPtrType iter;
    iter.m_node = node;
    Remove(&iter);
    return 1;
}

// ============================================================================
// ERedBlackTree::FindFirst - 0x802ce404 (108 bytes)
// Finds first (leftmost) node with given key by walking left children
// ============================================================================
// NON_MATCHING - register allocation
ERedBlackTreeNode* ERedBlackTree::FindFirst(unsigned int key, unsigned int* outValue) const {
    ERedBlackTreeNode* node = Find(key, 0);
    if (node == 0) {
        return 0;
    }
    // Walk to leftmost node with same key via m_next chain
    while (node->m_next != 0) {
        if (node->m_next->m_key != key) {
            break;
        }
        node = node->m_next;
    }
    if (outValue != 0) {
        *outValue = node->m_value;
    }
    return node;
}

// ============================================================================
// ERedBlackTree::RemoveAll - 0x802ce4a8 (96 bytes)
// Removes all: walks node list, frees each, resets tree state
// ============================================================================
// NON_MATCHING - loop structure
void ERedBlackTree::RemoveAll(void) {
    ERedBlackTreeNode* node = m_nodeList;
    while (node != 0) {
        ERedBlackTreeNode* next = node->m_next;
        __builtin_delete(node);
        node = next;
    }
    m_count = 0;
    m_root = &m_sentinel;
    m_nodeList = 0;
}

// ============================================================================
// ERedBlackTree::FreeAll - 0x802ce508 (100 bytes)
// Frees all values (heap pointers), then removes all
// ============================================================================
// NON_MATCHING - loop structure, iteration via m_color offset
void ERedBlackTree::FreeAll(void) {
    ERedBlackTreeNode* node = m_nodeList;
    while (1) {
        if (node == 0) break;
        void* value = (void*)node->m_value;
        EAHeap* heap = MainHeap();
        heap->Free(value);
        node = node->m_next;
    }
    RemoveAll();
}

// ============================================================================
// ERedBlackTree::operator=(ERedBlackTree&) - 0x802ce594 (68 bytes)
// Assignment: removes all, copies values from other
// ============================================================================
// NON_MATCHING - register allocation
ERedBlackTree& ERedBlackTree::operator=(ERedBlackTree& other) {
    RemoveAll();
    SetValues(other, true);
    return *this;
}

// ============================================================================
// ERedBlackTree::operator==(ERedBlackTree&) const - 0x802ce660 (132 bytes)
// Equality: walks both trees' ordered node lists, comparing key and value
// ============================================================================
int ERedBlackTree::operator==(ERedBlackTree& other) const {
    ERedBlackTreeNode* a = m_nodeList;
    ERedBlackTreeNode* b = other.m_nodeList;
    while (1) {
        bool aMore = (a != 0);
        if (!aMore) {
            // a is done - check if b is also done
            bool bMore = (b != 0);
            if (bMore) {
                return 0; // b has more, not equal
            }
            break;
        }
        bool bMore = (b != 0);
        if (!bMore) {
            return 0; // a has more, not equal
        }
        if (a->m_key != b->m_key) {
            return 0;
        }
        if (a->m_value != b->m_value) {
            return 0;
        }
        a = a->m_next;
        b = b->m_next;
    }
    // If b is not null, not equal
    if (b != 0) {
        return 0;
    }
    return 1;
}

// ============================================================================
// DbgLogTraceOpen - 0x802df2c8 (80 bytes)
// Opens a log file for trace output
// ============================================================================
// NON_MATCHING - SDA access, string constant addresses
void DbgLogTraceOpen(char* filename) {
    char buf[128];
    Sprintf(buf, (char*)"%s%s", filename, (char*)".log");
    g_log = (int)EString_fopen(buf, "w");
}

// ============================================================================
// DbgLogTrace - 0x802df34c (76 bytes)
// Saves all varargs to stack then returns - compiled-out trace in release build
// ============================================================================
// NON_MATCHING - varargs saving pattern is compiler-generated
void DbgLogTrace(char* format, ...) {
    // In release build: saves r4-r10 and f1-f8 to stack, then returns
    (void)format;
}

// ============================================================================
// StringWriter8 - 0x802dce84 (116 bytes)
// Callback for VprintfCore8: writes formatted output to a buffer
// context = StringWriterContext* { buffer, pos, max, pad }
// ============================================================================
// NON_MATCHING - register allocation, memcpy call
bool StringWriter8(char* data, unsigned int size, void* context) {
    StringWriterContext* ctx = (StringWriterContext*)context;
    unsigned int pos = ctx->m_pos;
    unsigned int max = ctx->m_max;
    unsigned int end = pos + size;
    if (end > max) {
        size = max - pos;
    }
    if (ctx->m_buffer != 0) {
        memcpy(ctx->m_buffer + pos, data, size);
    }
    ctx->m_pos = ctx->m_pos + size;
    return true;
}

// ============================================================================
// Vsnprintf - 0x802de768 (124 bytes)
// Formats string with va_list into buffer with max size
// ============================================================================
// NON_MATCHING - stack frame layout, StringWriterContext setup
int Vsnprintf(char* buf, unsigned int size, char* format, __va_list_tag* ap) {
    StringWriterContext ctx;
    ctx.m_buffer = buf;
    ctx.m_pos = 0;
    ctx.m_max = size;
    ctx.m_pad = 0;
    int result = VprintfCore8((WriteFunc)StringWriter8, &ctx, format, ap);
    if (buf != 0) {
        if (result >= 0) {
            if ((unsigned int)result < size) {
                buf[result] = 0;
            } else {
                buf[size - 1] = 0;
            }
        }
    }
    return result;
}
