// ea_containers.h - EHashTable, ERedBlackTree, EFixedPool, EGlobalManager declarations
// From: base_ngc_release_dvd.lib
//   e_hashtable.obj, e_redblacktree.obj, e_fixedpool.obj, e_globalmanager.obj

#ifndef EA_CONTAINERS_H
#define EA_CONTAINERS_H

// ============================================================================
// HTIteratorPtrType - hash table linked list node
// ============================================================================
struct HTIteratorPtrType {
    void* m_next;           // 0x00 - next node in bucket chain
    unsigned int m_padding; // 0x04
    unsigned int m_hash;    // 0x08 - can also be used as "next" pointer for iteration
    unsigned int m_key;     // 0x0C
    unsigned int m_value;   // 0x10
};

// ============================================================================
// EHashTable - EA hash table with chaining
// Layout:
//   0x00: m_count      - number of entries
//   0x04: m_headNode   - head of linked list of all nodes
//   0x08: m_table      - bucket array (unsigned int* / pointer to array)
//   0x0C: m_tableSize  - number of buckets
// ============================================================================
class EHashTable {
public:
    unsigned int m_count;       // 0x00
    HTIteratorPtrType* m_headNode; // 0x04 - linked list of all entries
    unsigned int* m_table;      // 0x08 - bucket array
    int m_tableSize;            // 0x0C

    EHashTable(int tableSize);
    EHashTable(EHashTable& other);
    ~EHashTable(void);

    void InitTable(int tableSize);
    void ClearTable(void);

    unsigned int& operator[](unsigned int key);
    unsigned int operator[](unsigned int key) const;
    void SetValue(unsigned int key, unsigned int value);
    HTIteratorPtrType* Insert(unsigned int bucketIdx, unsigned int key, bool overwrite);
    HTIteratorPtrType* InsertNew(unsigned int bucketIdx, unsigned int key, unsigned int value);
    void SetValues(EHashTable& other);

    HTIteratorPtrType* Find(unsigned int key, unsigned int* outValue) const;
    HTIteratorPtrType* Find(unsigned int key, unsigned int bucketIdx) const;
    HTIteratorPtrType* FindNext(HTIteratorPtrType* iter, unsigned int* outValue) const;

    int Remove(unsigned int key);
    void Remove(unsigned int key, HTIteratorPtrType* node);
    void Remove(HTIteratorPtrType* iter);
    void RemoveAll(void);

    void FreeAll(void);
    int GetSize(void) const;

    EHashTable& operator=(EHashTable& other);
    int operator==(EHashTable& other) const;

    void SetTableSize(int newSize);
    void AutoSizeTable(void);
};

// ============================================================================
// ERedBlackTreeNode
// Layout:
//   0x00: m_left
//   0x04: m_right
//   0x08: m_parent
//   0x0C: m_nextInOrder (linked list for iteration)
//   0x10: m_color (probably in the "next" chain node)
//   0x14: m_unused/reserved
//   0x18: m_key
//   0x1C: m_value
// ============================================================================
struct ERedBlackTreeNode {
    ERedBlackTreeNode* m_left;    // 0x00
    ERedBlackTreeNode* m_right;   // 0x04
    ERedBlackTreeNode* m_parent;  // 0x08
    ERedBlackTreeNode* m_next;    // 0x0C - linked list for ordered iteration
    int m_color;                  // 0x10 - 0 = black, 1 = red
    int m_reserved;               // 0x14
    unsigned int m_key;           // 0x18
    unsigned int m_value;         // 0x1C
};

// ============================================================================
// RBIteratorPtrType - red-black tree iteration state
// ============================================================================
struct RBIteratorPtrType {
    ERedBlackTreeNode* m_node;    // 0x00
    unsigned int m_key;           // 0x04
};

// ============================================================================
// ERedBlackTree - EA red-black tree
// Layout:
//   0x00: m_count
//   0x04: m_nodeList (linked list of all nodes, for freeing)
//   0x08: m_root
// ============================================================================
class ERedBlackTree {
public:
    unsigned int m_count;           // 0x00
    ERedBlackTreeNode* m_nodeList;  // 0x04 - linked list head for all allocated nodes
    ERedBlackTreeNode* m_root;      // 0x08 - root node (initially = &m_sentinel)

    static ERedBlackTreeNode m_sentinel; // sentinel / nil node

    ERedBlackTree(void);
    ERedBlackTree(ERedBlackTree& other);

    void RotateLeft(ERedBlackTreeNode* x);
    void RotateRight(ERedBlackTreeNode* x);
    void InsertFixup(ERedBlackTreeNode* z);
    void RemoveFixup(ERedBlackTreeNode* x);

    ERedBlackTreeNode* InsertAt(ERedBlackTreeNode* parent, unsigned int key, unsigned int value);

    unsigned int operator[](unsigned int key) const;
    unsigned int& operator[](unsigned int key);
    void SetValue(unsigned int key, unsigned int value);
    ERedBlackTreeNode* Insert(unsigned int key, unsigned int value, bool overwrite);

    ERedBlackTreeNode* FindKeyOrParent(unsigned int key) const;
    ERedBlackTreeNode* FindParent(unsigned int key) const;

    ERedBlackTreeNode* Find(unsigned int key, unsigned int* outValue) const;
    ERedBlackTreeNode* FindFirst(unsigned int key, unsigned int* outValue) const;
    ERedBlackTreeNode* FindNext(RBIteratorPtrType* iter, unsigned int* outValue) const;

    int Remove(unsigned int key);
    void Remove(RBIteratorPtrType* iter);
    void RemoveAll(void);

    void FreeAll(void);
    int GetSize(void) const;

    ERedBlackTree& operator=(ERedBlackTree& other);
    int operator==(ERedBlackTree& other) const;

    void SetValues(ERedBlackTree& other, bool deepCopy);
};

// ============================================================================
// EFixedPool - Fixed-size block pool allocator
// Layout:
//   0x00: m_count    - number of allocated blocks
//   0x04: m_buffer   - pointer to allocated buffer
//   0x08: (inherited EHashTable? or more fields)
// ============================================================================
class EFixedPool {
public:
    int m_count;        // 0x00
    void* m_buffer;     // 0x04

    EFixedPool(void);
    ~EFixedPool(void);

    void Init(int blockSize, int numBlocks);
    void Init(int blockSize, int numBlocks, void* buffer);
};

// ============================================================================
// EGlobalManagerClient - base class for things that register with EGlobalManager
// ============================================================================
class EGlobalManagerClient {
public:
    // vtable at some offset
    // Virtual functions include Startup() and Shutdown() at known vtable offsets
};

// ============================================================================
// EGlobalManager - manages global init/shutdown ordering
// ============================================================================
class EGlobalManager {
public:
    static int m_startupComplete;       // SDA-relative
    static int m_shutdownComplete;      // SDA-relative
    static int m_nClients;              // SDA-relative
    static int m_nStartedUpClients;     // SDA-relative

    static void Register(EGlobalManagerClient* client, int priority);
    static void Startup(void);
    static void Shutdown(void);
};

// ============================================================================
// ea_printf / trace related
// ============================================================================

// Forward declaration for varargs
struct __va_list_tag;

// FormatData used by EA's printf implementation
struct FormatData {
    // Internal format data - opaque to us
    char _data[128]; // placeholder
};

// StringWriter context for EA's printf
struct StringWriterContext {
    char* m_buffer;     // 0x00
    unsigned int m_pos; // 0x04
    unsigned int m_max; // 0x08
    unsigned int m_pad; // 0x0C
};

// EA printf functions
typedef bool (*WriteFunc)(char* buf, unsigned int size, void* context);

extern "C" {
    bool StringWriter8(char* data, unsigned int size, void* context);
    int VprintfCore8(WriteFunc writer, void* context, char* format, __va_list_tag* ap);
    int Vsnprintf(char* buf, unsigned int size, char* format, __va_list_tag* ap);
    int Printf(char* format, ...);
    int Sprintf(char* buf, char* format, ...);
    int Snprintf(char* buf, unsigned int size, char* format, ...);
    int Vsprintf(char* buf, char* format, __va_list_tag* ap);
    int Sscanf(char* str, char* format, ...);
    double AtoF(char* str);
    int AtoI(char* str);
}

// Trace/logging functions
extern "C" {
    void EORDbgTrace(char* format, ...);
    void MaxisDbgTraceBinary(void* data, unsigned int size);
    void DbgLogTraceOpen(char* filename);
    void DbgLogTraceClose(void);
    void DbgLogTrace(char* format, ...);
}

// Trace globals (SDA)
extern int g_log; // file handle for trace log
extern int _enable_trace_log;
extern int _enable_proview;

#endif // EA_CONTAINERS_H
