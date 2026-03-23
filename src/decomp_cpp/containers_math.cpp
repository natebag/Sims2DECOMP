// containers_math.cpp - Portable C++ decompilation of core container and math classes
//
// Converted from inline PPC asm (src/asm_decomp/*.cpp) using reference
// documentation in src/core/containers_decomp.cpp and src/core/math_utils_decomp.cpp.
//
// Classes covered:
//   1. EString        - Simple owning C string wrapper (no refcount)
//   2. BString        - Reference-counted string with copy-on-write
//   3. EHashTable     - Open-chaining hash table (key=u32, value=u32)
//   4. ERedBlackTree  - Balanced BST (key=u32, value=u32)
//   5. TArray<T,A>    - Templated dynamic array
//   6. EVec3          - 3D vector operations
//   7. EMat4          - 4x4 row-major matrix operations
//   8. CTilePt        - Isometric tile coordinates (3 signed bytes)
//   9. EController    - GameCube input controller
//
// Source: Disassembly of u2_ngc_release_dvd.elf
//         Symbol names from u2_ngc_release.map (39,169 symbols)
//         Struct layouts from include/classes/*.h
//
// Build: SN Systems ProDG for GameCube (SN-NGC), DolphinSDK 1.0 HW2

#include "types.h"

// ============================================================================
// External functions and types
// ============================================================================

extern "C" {
    void* memcpy(void* dst, const void* src, unsigned int n);
    void* memset(void* s, int c, unsigned int n);
    int   strcmp(const char* a, const char* b);
    int   strlen(const char* s);
    char* strchr(const char* s, int c);
    float sinf(float);
    float cosf(float);
    float atan2f(float, float);
    float sqrtf(float);
    float fabsf(float);
    void  EORDbgTrace(const char* fmt, ...);
}

// Forward declarations
class EAHeap;
extern EAHeap* MainHeap();

class EAHeap {
public:
    void* Malloc(unsigned int size, int flags);
    void  Free(void* ptr);
};

struct EVec3;
struct EVec4;
struct EQuat;
struct EBtnToCmdAssoc;

extern void EMat4_Mult4x4_Impl(struct EMat4& out, struct EMat4& a, struct EMat4& b);
extern float EVec3_Length(EVec3* v);
extern void EVec3_Normalize(EVec3* out, EVec3* in);
extern void EQuat_ToMat4(EQuat* quat, struct EMat4* mat);
extern void EQuat_ExtractAxisAngle(EQuat* quat, EVec3* axis);
extern void operator_delete_impl(void* ptr);
extern void* operator_new_impl(unsigned int size);


// ############################################################################
//
//  SECTION 1: EString - Simple Owning C String
//
//  Layout: 4 bytes (single char* pointer)
//  No reference counting. Copy = deep copy via MakeCopy.
//  Empty state uses static m_null sentinel.
//
// ############################################################################

class EString {
public:
    char* m_buffer;         // 0x00 - pointer to heap-allocated null-terminated string
    static char m_null;     // shared null sentinel (1 byte, value 0)

    // --- Internal buffer management ---

    // 0x802D293C (12 bytes)
    void SetToNull() {
        m_buffer = &m_null;
    }

    // 0x802D2948 (44 bytes)
    void Deallocate(char* buf) {
        if (buf != &m_null) {
            FreeBuffer(buf);
        }
    }

    // 0x802D29AC (52 bytes)
    void FreeBuffer(char* buf) {
        EAHeap* heap = MainHeap();
        heap->Free(buf);
    }

    // 0x802D2974 (56 bytes)
    char* AllocBuffer(int size) {
        EAHeap* heap = MainHeap();
        return (char*)heap->Malloc(size, 0);
    }

    // --- Constructors ---

    // 0x802D2844 (60 bytes)
    EString(char c) {
        char tmp[2];
        tmp[0] = c;
        tmp[1] = 0;
        MakeCopy(tmp);
    }

    // 0x802D2880 (188 bytes)
    // Concatenation constructor: allocates start+append as one string.
    EString(char* start, char* append) {
        int startLen = 0;
        int appendLen = 0;

        if (start != NULL) {
            startLen = strlen(start);
        }
        if (append != NULL) {
            appendLen = strlen(append);
        }

        int totalLen = startLen + appendLen;
        if (totalLen == 0) {
            SetToNull();
            return;
        }

        char* buf = AllocBuffer(totalLen + 1);
        if (buf == NULL) {
            SetToNull();
            return;
        }

        memcpy(buf, start, startLen);
        memcpy(buf + startLen, append, appendLen + 1); // includes null terminator
        m_buffer = buf;
    }

    // --- Core operations ---

    // 0x802D2B60 (132 bytes)
    void MakeCopy(char* src) {
        if (src == NULL) {
            SetToNull();
            return;
        }
        int len = strlen(src);
        if (len == 0) {
            SetToNull();
            return;
        }
        int allocSize = len + 1;
        char* buf = AllocBuffer(allocSize);
        if (buf == NULL) {
            SetToNull();
            return;
        }
        memcpy(buf, src, allocSize);
        m_buffer = buf;
    }

    // 0x802D2BE4 (64 bytes)
    EString& operator=(char* str) {
        char* old = m_buffer;
        MakeCopy(str);
        Deallocate(old);
        return *this;
    }

    // 0x802D2C24 (36 bytes)
    int GetLength() const {
        return strlen(m_buffer);
    }

    // 0x802D2D40 (56 bytes)
    void Empty() {
        Deallocate(m_buffer);
        SetToNull();
    }

    // 0x802D2CB0 (144 bytes)
    int Allocate(int newLen) {
        if (newLen == 0) {
            Empty();
            return 1;
        }
        int curLen = GetLength();
        if (newLen <= curLen) {
            return 1;
        }
        char* newBuf = AllocBuffer(newLen + 1);
        if (newBuf == NULL) {
            return 0;
        }
        memcpy(newBuf, m_buffer, curLen + 1);
        Deallocate(m_buffer);
        m_buffer = newBuf;
        return 1;
    }

    // 0x802D2D78 (112 bytes)
    int Compare(char* other) const {
        if (m_buffer[0] == 0) {
            if (other == NULL || other[0] == 0) return 0;
            return -1;
        }
        if (other == NULL || other[0] == 0) return 1;
        return strcmp(m_buffer, other);
    }

    // 0x802D3198 (96 bytes)
    int Find(char c, int startPos) const {
        if (m_buffer[0] == 0) return -1;
        char* found = strchr(m_buffer + startPos, c);
        if (found == NULL) return -1;
        return (int)(found - m_buffer);
    }

    // 0x802D30A8 (88 bytes)
    EString& operator+=(char* other) {
        EString temp(m_buffer, other);
        *this = temp.m_buffer;
        temp.Deallocate(temp.m_buffer);
        return *this;
    }

    // 0x802D2F6C (120 bytes)
    // NON_MATCHING: simplified Mid; actual uses Left helper for count != -1
    EString Mid(int start, int count) const {
        EString result;
        result.SetToNull();
        if (count == -1) {
            result.MakeCopy(m_buffer + start);
        } else {
            result.MakeCopy(m_buffer + start);
            // Truncate to 'count' characters
            if (result.GetLength() > count) {
                result.m_buffer[count] = '\0';
            }
        }
        return result;
    }

    // 0x803B0A6C (8 bytes)
    operator char*() const {
        return m_buffer;
    }
};

char EString::m_null = '\0';


// ############################################################################
//
//  SECTION 2: basic_string_ref / BString - Reference-Counted Strings
//
//  basic_string_ref: 16-byte ref-counted buffer (data, length, capacity, refcount)
//  BString: 4-byte handle pointing to a shared basic_string_ref
//  Copy-on-write semantics: copy shares ref, mutate creates private copy
//
// ############################################################################

struct basic_string_ref {
    char* m_data;       // 0x00 - pointer to character data
    u32   m_length;     // 0x04 - string length (not counting null)
    u32   m_capacity;   // 0x08 - allocated capacity in chars (not counting null)
    u32   m_refCount;   // 0x0C - reference count (starts at 1)

    // 0x8009C914 (188 bytes)
    basic_string_ref(char* src) {
        if (src != NULL) {
            m_length = strlen(src);
            m_capacity = m_length;
        } else {
            m_length = 0;
            m_capacity = 0;
        }
        if (m_capacity != 0) {
            m_capacity = m_capacity + 1;
            char* buf = (char*)MainHeap()->Malloc(m_capacity, 0);
            m_data = buf;
            memcpy(buf, src, m_length);
            m_data[m_length] = '\0';
        } else {
            m_data = NULL;
        }
        m_refCount = 1;
    }

    // 0x8009BF5C (80 bytes)
    void delete_ptr() {
        if (m_capacity != 0) {
            MainHeap()->Free(m_data);
            m_data = NULL;
            m_capacity = 0;
        }
    }
};

// Global shared empty string ref
static basic_string_ref s_emptyRef = { NULL, 0, 0, 0x7FFFFFFF };
static const char s_emptyString[] = "";

class BString {
public:
    basic_string_ref* m_ref;  // 0x00 - pointer to shared ref-counted buffer

    // 0x8009D6F8 (32 bytes)
    BString() {
        m_ref = &s_emptyRef;
        s_emptyRef.m_refCount++;
    }

    // 0x8009C014 (12 bytes)
    int ref_count() const {
        return m_ref->m_refCount;
    }

    // 0x8009FF4C (12 bytes)
    unsigned int length() const {
        return m_ref->m_length;
    }

    // 0x8009C064 (12 bytes)
    char* point() {
        return m_ref->m_data;
    }

    // 0x8009C020 (68 bytes)
    char* data() const {
        if (m_ref->m_length == 0) return NULL;
        return m_ref->m_data;
    }

    // 0x8009ECF8 (48 bytes)
    const char* c_str() const {
        char* d = NULL;
        if (m_ref->m_length != 0) {
            d = m_ref->m_data;
        }
        if (d == NULL) {
            return s_emptyString;
        }
        return d;
    }

    // 0x8009BFB4 (96 bytes)
    void delete_ref() {
        m_ref->m_refCount--;
        if (m_ref->m_refCount == 0) {
            m_ref->delete_ptr();
            MainHeap()->Free(m_ref);
        }
    }

    // Destructor
    ~BString() {
        delete_ref();
    }

    // 0x8009D9D4 (152 bytes)
    BString& operator=(BString& src) {
        if (this == &src) return *this;

        delete_ref();

        if (src.ref_count() != -1) {
            // Share the ref (cheap copy)
            m_ref = src.m_ref;
            m_ref->m_refCount++;
        } else {
            // Deep copy: allocate new ref (16 bytes)
            basic_string_ref* newRef =
                (basic_string_ref*)MainHeap()->Malloc(16, 0);
            // Copy source data into new ref
            char* srcData = src.point();
            if (srcData != NULL) {
                *newRef = basic_string_ref(srcData);
            } else {
                newRef->m_data = NULL;
                newRef->m_length = 0;
                newRef->m_capacity = 0;
                newRef->m_refCount = 1;
            }
            m_ref = newRef;
        }
        return *this;
    }
};


// ############################################################################
//
//  SECTION 3: EHashTable - Open-Chaining Hash Table
//
//  Maps u32 keys to u32 values. Uses separate chaining (linked list per
//  bucket). Maintains a global doubly-linked list for fast iteration.
//
//  Table layout: 20 bytes
//  Node layout:  20 bytes
//
// ############################################################################

struct EHashTableNode {
    EHashTableNode* m_globalNext;   // 0x00 - next in global linked list
    EHashTableNode* m_globalPrev;   // 0x04 - prev in global linked list
    EHashTableNode* m_bucketNext;   // 0x08 - next in same hash bucket chain
    u32             m_key;          // 0x0C - the key
    u32             m_value;        // 0x10 - the value
};

class EHashTable {
public:
    EHashTableNode*  m_head;        // 0x00 - head of global linked list
    EHashTableNode*  m_tail;        // 0x04 - tail of global linked list
    EHashTableNode** m_buckets;     // 0x08 - array of bucket head pointers
    u32              m_tableSize;   // 0x0C - number of buckets
    u32              m_sentinel;    // 0x10 - used by Find iterator

    // 0x802C88C4 (60 bytes)
    EHashTable(int tableSize) {
        m_head = NULL;
        m_tail = NULL;
        InitTable(tableSize);
    }

    // 0x802C8900 (80 bytes) - Copy constructor
    EHashTable(EHashTable& other) {
        m_head = NULL;
        m_tail = NULL;
        InitTable(other.m_tableSize);
        SetValues(other);
    }

    // 0x802C8950 (76 bytes)
    ~EHashTable() {
        RemoveAll();
        MainHeap()->Free(m_buckets);
    }

    // 0x802C899C (80 bytes)
    void InitTable(int tableSize) {
        EAHeap* heap = MainHeap();
        m_buckets = (EHashTableNode**)heap->Malloc(tableSize * 4, 0);
        m_tableSize = tableSize;
        ClearTable();
    }

    // 0x802C89EC (48 bytes)
    void ClearTable() {
        memset(m_buckets, 0, m_tableSize * 4);
    }

    // 0x802C8B1C (140 bytes)
    void Insert(unsigned int key, unsigned int value, bool allowDuplicates) {
        unsigned int bucket = key % m_tableSize;

        if (allowDuplicates) {
            InsertNew(bucket, key, value);
        } else {
            EHashTableNode* existing = FindInBucket(bucket, key);
            if (existing == NULL) {
                InsertNew(bucket, key, value);
            }
        }
    }

    // 0x802C8BA8 (148 bytes)
    EHashTableNode* InsertNew(unsigned int bucket, unsigned int key,
                              unsigned int value) {
        EHashTableNode* node =
            (EHashTableNode*)MainHeap()->Malloc(20, 0);
        if (node == NULL) return NULL;

        node->m_key = key;
        node->m_value = value;

        // Link into bucket chain (prepend)
        node->m_bucketNext = m_buckets[bucket];
        m_buckets[bucket] = node;

        // Link into global doubly-linked list (prepend to tail)
        node->m_globalNext = m_tail;
        if (m_tail != NULL) {
            m_tail->m_globalPrev = node;
        } else {
            m_head = node;
        }
        node->m_globalPrev = NULL;
        m_tail = node;

        return node;
    }

    // 0x802C8D78 (88 bytes)
    EHashTableNode* Find(unsigned int key, unsigned int* valueOut) const {
        unsigned int bucket = key % m_tableSize;
        EHashTableNode* node = m_buckets[bucket];

        while (node != NULL) {
            if (node->m_key == key) {
                if (valueOut != NULL) {
                    *valueOut = node->m_value;
                }
                return node;
            }
            node = node->m_bucketNext;
        }
        return NULL;
    }

    // 0x802C8F0C (40 bytes)
    int GetSize() const {
        int count = 0;
        EHashTableNode* node = m_head;
        while (node != NULL) {
            node = node->m_globalPrev;
            count++;
        }
        return count;
    }

    // RemoveAll - frees all nodes via the global linked list
    void RemoveAll() {
        EHashTableNode* node = m_tail;
        while (node != NULL) {
            EHashTableNode* next = node->m_globalNext;
            MainHeap()->Free(node);
            node = next;
        }
        m_head = NULL;
        m_tail = NULL;
        ClearTable();
    }

    // SetValues - copies all entries from another table
    void SetValues(EHashTable& other) {
        EHashTableNode* node = other.m_tail;
        while (node != NULL) {
            Insert(node->m_key, node->m_value, true);
            node = node->m_globalNext;
        }
    }

private:
    // Internal: find a node in a specific bucket by key
    EHashTableNode* FindInBucket(unsigned int bucket, unsigned int key) const {
        EHashTableNode* node = m_buckets[bucket];
        while (node != NULL) {
            if (node->m_key == key) return node;
            node = node->m_bucketNext;
        }
        return NULL;
    }
};


// ############################################################################
//
//  SECTION 4: ERedBlackTree - Balanced Binary Search Tree
//
//  Standard CLRS red-black tree mapping u32 keys to u32 values.
//  Maintains a flat linked list alongside the BST for fast iteration.
//
//  Tree layout: 12 bytes (head, tail, root)
//  Node layout: 32 bytes
//  Static sentinel node acts as "nil" leaf (black).
//
// ############################################################################

struct ERedBlackTreeNode {
    ERedBlackTreeNode* m_left;      // 0x00 - left child
    ERedBlackTreeNode* m_right;     // 0x04 - right child
    ERedBlackTreeNode* m_parent;    // 0x08 - parent node
    ERedBlackTreeNode* m_listPrev;  // 0x0C - prev in flat linked list
    ERedBlackTreeNode* m_listNext;  // 0x10 - next in flat linked list
    u32                m_color;     // 0x14 - 0=BLACK, 1=RED
    u32                m_key;       // 0x18 - the key
    u32                m_value;     // 0x1C - the value
};

class ERedBlackTree {
public:
    ERedBlackTreeNode* m_head;      // 0x00 - head of flat linked list
    ERedBlackTreeNode* m_tail;      // 0x04 - tail of flat linked list
    ERedBlackTreeNode* m_root;      // 0x08 - root of the BST

    static ERedBlackTreeNode m_sentinel; // sentinel / nil node (BLACK)

    // 0x802CD9B8 (32 bytes)
    ERedBlackTree() {
        m_head = NULL;
        m_root = &m_sentinel;
        m_tail = NULL;
    }

    // 0x802CD9D8 (76 bytes) - Copy constructor
    ERedBlackTree(ERedBlackTree& other) {
        m_head = NULL;
        m_root = &m_sentinel;
        m_tail = NULL;
        SetValues(other, true);
    }

    // --- BST search ---

    // 0x802CDCEC (72 bytes)
    ERedBlackTreeNode* FindKeyOrParent(unsigned int key) const {
        ERedBlackTreeNode* node = m_root;
        ERedBlackTreeNode* parent = NULL;

        while (node != &m_sentinel) {
            if (key == node->m_key) return node;
            parent = node;
            if (key < node->m_key) {
                node = node->m_left;
            } else {
                node = node->m_right;
            }
        }
        return parent;
    }

    // FindParent - same as FindKeyOrParent but always returns the parent
    ERedBlackTreeNode* FindParent(unsigned int key) const {
        ERedBlackTreeNode* node = m_root;
        ERedBlackTreeNode* parent = NULL;

        while (node != &m_sentinel) {
            parent = node;
            if (key < node->m_key) {
                node = node->m_left;
            } else {
                node = node->m_right;
            }
        }
        return parent;
    }

    // 0x802CE3AC (88 bytes)
    ERedBlackTreeNode* Find(unsigned int key, unsigned int* valueOut) const {
        ERedBlackTreeNode* node = m_root;

        while (node != &m_sentinel) {
            if (key == node->m_key) {
                if (valueOut != NULL) {
                    *valueOut = node->m_value;
                }
                return node;
            }
            if (key < node->m_key) {
                node = node->m_left;
            } else {
                node = node->m_right;
            }
        }
        return NULL;
    }

    // --- Insertion ---

    // 0x802CDDD8 (128 bytes)
    ERedBlackTreeNode* Insert(unsigned int key, unsigned int value,
                              bool allowDuplicates) {
        if (allowDuplicates) {
            ERedBlackTreeNode* parent = FindParent(key);
            return InsertAt(parent, key, value);
        } else {
            ERedBlackTreeNode* existing = FindKeyOrParent(key);
            if (existing != NULL && existing->m_key == key) {
                return NULL; // duplicate
            }
            return InsertAt(existing, key, value);
        }
    }

    // 0x802CDE58 (336 bytes)
    ERedBlackTreeNode* InsertAt(ERedBlackTreeNode* parent,
                                unsigned int key, unsigned int value) {
        ERedBlackTreeNode* node =
            (ERedBlackTreeNode*)MainHeap()->Malloc(32, 0);
        if (node == NULL) return NULL;

        node->m_color = 1;              // RED
        node->m_right = &m_sentinel;
        node->m_parent = parent;
        node->m_value = value;
        node->m_left = &m_sentinel;
        node->m_key = key;

        if (parent == NULL) {
            // Tree was empty
            m_root = node;
            node->m_listNext = m_head;
            if (m_head != NULL) {
                m_head->m_listPrev = node;
            } else {
                m_tail = node;
            }
            node->m_listPrev = NULL;
            m_head = node;
        } else if (key < parent->m_key) {
            // Insert as left child
            parent->m_left = node;
            node->m_listPrev = parent->m_listPrev;
            if (parent->m_listPrev != NULL) {
                parent->m_listPrev->m_listNext = node;
            } else {
                // node becomes new head
                m_head = node;
            }
            parent->m_listPrev = node;
            node->m_listNext = parent;
        } else {
            // Insert as right child
            parent->m_right = node;
            node->m_listNext = parent->m_listNext;
            if (parent->m_listNext != NULL) {
                parent->m_listNext->m_listPrev = node;
            } else {
                m_tail = node;
            }
            parent->m_listNext = node;
            node->m_listPrev = parent;
        }

        InsertFixup(node);
        return node;
    }

    // --- Rotations ---

    // 0x802CDA24 (124 bytes)
    void RotateLeft(ERedBlackTreeNode* node) {
        ERedBlackTreeNode* y = node->m_right;

        node->m_right = y->m_left;
        if (y->m_left != &m_sentinel) {
            y->m_left->m_parent = node;
        }

        if (y != &m_sentinel) {
            y->m_parent = node->m_parent;
        }

        if (node->m_parent != NULL) {
            if (node == node->m_parent->m_left) {
                node->m_parent->m_left = y;
            } else {
                node->m_parent->m_right = y;
            }
        } else {
            m_root = y;
        }

        y->m_left = node;
        if (node != &m_sentinel) {
            node->m_parent = y;
        }
    }

    // 0x802CDAA0 (124 bytes)
    void RotateRight(ERedBlackTreeNode* node) {
        ERedBlackTreeNode* y = node->m_left;

        node->m_left = y->m_right;
        if (y->m_right != &m_sentinel) {
            y->m_right->m_parent = node;
        }

        if (y != &m_sentinel) {
            y->m_parent = node->m_parent;
        }

        if (node->m_parent != NULL) {
            if (node == node->m_parent->m_right) {
                node->m_parent->m_right = y;
            } else {
                node->m_parent->m_left = y;
            }
        } else {
            m_root = y;
        }

        y->m_right = node;
        if (node != &m_sentinel) {
            node->m_parent = y;
        }
    }

    // --- Rebalancing ---

    // 0x802CDB1C (328 bytes)
    void InsertFixup(ERedBlackTreeNode* node) {
        while (node != m_root && node->m_parent->m_color == 1 /* RED */) {
            ERedBlackTreeNode* parent = node->m_parent;
            ERedBlackTreeNode* grandparent = parent->m_parent;

            if (parent == grandparent->m_left) {
                ERedBlackTreeNode* uncle = grandparent->m_right;
                if (uncle->m_color == 1 /* RED */) {
                    // Case 1: uncle is red - recolor
                    parent->m_color = 0;      // BLACK
                    uncle->m_color = 0;       // BLACK
                    grandparent->m_color = 1; // RED
                    node = grandparent;
                } else {
                    if (node == parent->m_right) {
                        // Case 2: node is right child - rotate left
                        node = parent;
                        RotateLeft(node);
                    }
                    // Case 3: node is left child - rotate right
                    node->m_parent->m_color = 0;                  // BLACK
                    node->m_parent->m_parent->m_color = 1;        // RED
                    RotateRight(node->m_parent->m_parent);
                }
            } else {
                // Mirror: parent is right child
                ERedBlackTreeNode* uncle = grandparent->m_left;
                if (uncle->m_color == 1 /* RED */) {
                    parent->m_color = 0;
                    uncle->m_color = 0;
                    grandparent->m_color = 1;
                    node = grandparent;
                } else {
                    if (node == parent->m_left) {
                        node = parent;
                        RotateRight(node);
                    }
                    node->m_parent->m_color = 0;
                    node->m_parent->m_parent->m_color = 1;
                    RotateLeft(node->m_parent->m_parent);
                }
            }
        }
        m_root->m_color = 0; // root must always be BLACK
    }

    // 0x802CE56C (40 bytes)
    int GetSize() const {
        int count = 0;
        ERedBlackTreeNode* node = m_head;
        while (node != NULL) {
            node = node->m_listNext;
            count++;
        }
        return count;
    }

    // RemoveAll - frees all nodes via flat linked list
    void RemoveAll() {
        ERedBlackTreeNode* node = m_head;
        while (node != NULL) {
            ERedBlackTreeNode* next = node->m_listNext;
            MainHeap()->Free(node);
            node = next;
        }
        m_head = NULL;
        m_tail = NULL;
        m_root = &m_sentinel;
    }

    // SetValues - deep copies entries from another tree
    void SetValues(ERedBlackTree& other, bool allowDuplicates) {
        ERedBlackTreeNode* node = other.m_head;
        while (node != NULL) {
            Insert(node->m_key, node->m_value, allowDuplicates);
            node = node->m_listNext;
        }
    }
};

// Static sentinel node (all zeros = BLACK, no children, no key)
ERedBlackTreeNode ERedBlackTree::m_sentinel = {
    NULL, NULL, NULL, NULL, NULL, 0, 0, 0
};


// ############################################################################
//
//  SECTION 5: TArray<T, Allocator> - Templated Dynamic Array
//
//  Layout: 12 bytes (m_data, m_size, m_capacity)
//  Uses power-of-2 growth strategy.
//  Allocator policy controls where memory comes from.
//
// ############################################################################

struct TArrayDefaultAllocator {
    static void* Alloc(unsigned int size, int alignment) {
        return MainHeap()->Malloc(size, alignment);
    }
    static void Free(void* ptr) {
        MainHeap()->Free(ptr);
    }
};

template <typename T, typename Allocator = TArrayDefaultAllocator>
class TArray {
public:
    T*  m_data;       // 0x00 - pointer to element array
    u32 m_size;       // 0x04 - number of valid elements
    u32 m_capacity;   // 0x08 - allocated capacity (in elements)

    // 0x8039BD90 (20 bytes)
    void Init() {
        m_size = 0;
        m_data = NULL;
        m_capacity = 0;
    }

    // Element lifecycle operations (trivial versions shown; non-trivial
    // types specialize these via template instantiation)
    void Construct(T* dst, int count) {
        for (int i = 0; i < count; i++) {
            // Default-construct each element (placement new equivalent)
            dst[i] = T();
        }
    }

    void Destruct(T* ptr, int count) {
        for (int i = 0; i < count; i++) {
            ptr[i].~T();
        }
    }

    void Copy(T* dst, T* src, int count) {
        for (int i = 0; i < count; i++) {
            dst[i] = src[i];
        }
    }

    void CopyReverse(T* dst, T* src, int count) {
        for (int i = count - 1; i >= 0; i--) {
            dst[i] = src[i];
        }
    }

    // Core resize logic
    // 0x8039C468 / 0x803C28EC (292 bytes)
    void SetSize(int newSize, int newCap) {
        if (newCap == 0) newCap = newSize;

        // If shrinking, destruct excess elements
        if (newSize < (int)m_size) {
            Destruct(m_data + newSize, m_size - newSize);
        }

        if (newCap == 0) {
            Allocator::Free(m_data);
            Init();
            return;
        }

        int oldSize = m_size;

        if (newCap != (int)m_capacity) {
            T* newBuf = (T*)Allocator::Alloc(newCap * sizeof(T), 8);
            if (newBuf == NULL) return;

            if (m_data != NULL) {
                int copyCount = newSize;
                if (copyCount > (int)m_size) copyCount = m_size;

                Construct(newBuf, copyCount);
                Copy(newBuf, m_data, copyCount);
                Destruct(m_data, m_size);
                Allocator::Free(m_data);
            }

            m_data = newBuf;
            m_capacity = newCap;
        }
        m_size = newSize;

        // If growing, construct new elements
        if (newSize > oldSize) {
            Construct(m_data + oldSize, newSize - oldSize);
        }
    }

    // 0x803C2A78 (216 bytes)
    void Insert(T* src, int pos, int count) {
        int newSize = m_size + count;

        if (newSize > (int)m_capacity) {
            // Grow with power-of-2
            int newCap = 1;
            while (newCap < newSize) {
                newCap *= 2;
            }
            SetSize(newSize, newCap);
        } else {
            int oldSize = m_size;
            m_size = newSize;
            Construct(m_data + oldSize, count);
        }

        if (pos != (int)m_size - count) {
            // Shift existing elements right
            CopyReverse(m_data + pos + count, m_data + pos,
                        m_size - pos - count);
        }

        // Copy new elements into the gap
        Copy(m_data + pos, src, count);
    }

    // 0x803C2B50 (40 bytes)
    void Add(T& item) {
        Insert(&item, m_size, 1);
    }
};


// ############################################################################
//
//  SECTION 6: EVec3 - 3D Vector Operations
//
//  Layout: 12 bytes (3 floats: x, y, z)
//
// ############################################################################

struct EVec2 {
    float x; // 0x00
    float y; // 0x04

    // 0x802D5A34 (56 bytes)
    void Print() {
        EORDbgTrace("%f %f\n", x, y);
    }
};

struct EVec3 {
    float x; // 0x00
    float y; // 0x04
    float z; // 0x08

    // 0x802D5A6C (60 bytes)
    void Print() {
        EORDbgTrace("%f %f %f\n", x, y, z);
    }

    // 0x802D5AA8 (120 bytes)
    // Converts normalized float [0,1] components to unsigned byte [0,255]
    void ToU8s(unsigned char* out) const {
        const float* src = &x;
        for (int i = 0; i < 3; i++) {
            float val = src[i] * 255.0f;
            if (val < 0.0f) {
                out[i] = 0;
            } else if (val > 255.0f) {
                out[i] = 255;
            } else {
                out[i] = (unsigned char)(int)val;
            }
        }
    }

    // 0x802D5B20 (88 bytes)
    // Converts unsigned byte [0,255] to normalized float [0,1]
    void FromU8s(unsigned char* in) {
        float* dst = &x;
        for (int i = 0; i < 3; i++) {
            dst[i] = (float)in[i] * (1.0f / 255.0f);
        }
    }

    // 0x802D5B78 (120 bytes)
    // Converts normalized float [-1,1] to signed byte [-127,127]
    void ToS8s(signed char* out) const {
        const float* src = &x;
        for (int i = 0; i < 3; i++) {
            float val = src[i] * 127.0f;
            if (val < -127.0f) {
                out[i] = -127;
            } else if (val > 127.0f) {
                out[i] = 127;
            } else {
                out[i] = (signed char)(int)val;
            }
        }
    }

    // 0x802D5BF0 (96 bytes)
    // Converts signed byte [-127,127] to normalized float [-1,1]
    void FromS8s(signed char* in) {
        float* dst = &x;
        for (int i = 0; i < 3; i++) {
            dst[i] = (float)in[i] * (1.0f / 127.0f);
        }
    }
};

struct EVec4 {
    float x, y, z, w;

    // 0x80361F34 (4 bytes) - empty stub in release build
    void Print() {}
};

struct EQuat {
    float x, y, z, w;

    // 0x802CCB00 (4 bytes) - empty stub in release build
    void Print() {}
};


// ############################################################################
//
//  SECTION 7: EMat4 - 4x4 Row-Major Matrix
//
//  Layout: 64 bytes (float m[4][4])
//  Row-major: m[row][col]
//  Row 3 = translation, columns 0-2 of upper 3x3 = local axes
//
// ############################################################################

class EMat4 {
public:
    float m[4][4]; // 0x00 - 64 bytes

    // 0x802C9208 (48 bytes)
    void Mult4x4(EMat4& a, EMat4& b) {
        EMat4_Mult4x4_Impl(a, b, *this);
    }

    // 0x802C9238 (56 bytes)
    // Scales upper 3x3 (rows 0-2) by uniform scalar. Row 3 untouched.
    void PreScale(float scale) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 4; col++) {
                m[row][col] *= scale;
            }
        }
    }

    // 0x802C9270 (152 bytes)
    // Non-uniform scale: row i *= v[i]
    void PreScale(EVec3& v) {
        m[0][0] *= v.x; m[0][1] *= v.x; m[0][2] *= v.x;
        m[1][0] *= v.y; m[1][1] *= v.y; m[1][2] *= v.y;
        m[2][0] *= v.z; m[2][1] *= v.z; m[2][2] *= v.z;
    }

    // 0x802C9308 (72 bytes)
    // Pre-translates in local space through rotation
    void PreTranslate(EVec3& v) {
        for (int c = 0; c < 3; c++) {
            float accum = v.y * m[1][c];
            accum = v.x * m[0][c] + accum;
            accum = v.z * m[2][c] + accum;
            m[3][c] += accum;
        }
    }

    // 0x802C9454 (72 bytes)
    // Fills all 16 elements with the same value.
    EMat4& operator=(float val) {
        m[0][0] = val; m[0][1] = val; m[0][2] = val; m[0][3] = val;
        m[1][0] = val; m[1][1] = val; m[1][2] = val; m[1][3] = val;
        m[2][0] = val; m[2][1] = val; m[2][2] = val; m[2][3] = val;
        m[3][0] = val; m[3][1] = val; m[3][2] = val; m[3][3] = val;
        return *this;
    }

    // 0x802C949C (40 bytes)
    void GetColumn(int col, EVec3& out) {
        out.x = m[0][col];
        out.y = m[1][col];
        out.z = m[2][col];
    }

    // 0x802C94C4 (52 bytes)
    void GetColumn(int col, EVec4& out) {
        out.x = m[0][col];
        out.y = m[1][col];
        out.z = m[2][col];
        out.w = m[3][col];
    }

    // 0x802C94F8 (40 bytes)
    void SetColumn(int col, EVec3& in) {
        m[0][col] = in.x;
        m[1][col] = in.y;
        m[2][col] = in.z;
    }

    // 0x802C9520 (52 bytes)
    void SetColumn(int col, EVec4& in) {
        m[0][col] = in.x;
        m[1][col] = in.y;
        m[2][col] = in.z;
        m[3][col] = in.w;
    }

    // 0x802C9554 (160 bytes)
    void Normalize() {
        EVec3 col;
        for (int i = 0; i <= 2; i++) {
            GetColumn(i, col);
            if (col.x != 0.0f || col.y != 0.0f || col.z != 0.0f) {
                EVec3_Normalize(&col, &col);
            }
            SetColumn(i, col);
        }
    }

    // 0x802C95F4 (76 bytes)
    void Transpose(EMat4& src) {
        for (int row = 0; row <= 3; row++) {
            for (int col = 0; col < 4; col++) {
                m[col][row] = src.m[row][col];
            }
        }
    }

    // 0x802C9640 (152 bytes)
    // In-place transpose: swaps m[i][j] with m[j][i] for all i != j
    void Transpose() {
        float tmp;
        tmp = m[0][1]; m[0][1] = m[1][0]; m[1][0] = tmp;
        tmp = m[0][2]; m[0][2] = m[2][0]; m[2][0] = tmp;
        tmp = m[0][3]; m[0][3] = m[3][0]; m[3][0] = tmp;
        tmp = m[1][2]; m[1][2] = m[2][1]; m[2][1] = tmp;
        tmp = m[1][3]; m[1][3] = m[3][1]; m[3][1] = tmp;
        tmp = m[2][3]; m[2][3] = m[3][2]; m[3][2] = tmp;
    }

    // 0x802C96D8 (88 bytes)
    void Id() {
        m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
        m[1][0] = 0.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
        m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][3] = 0.0f;
        m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f;
        m[3][3] = 0.0f;
        m[0][0] = 1.0f;
        m[1][1] = 1.0f;
        m[2][2] = 1.0f;
    }

    // 0x802C9730 (80 bytes)
    void Translate(EVec3& v) {
        Id();
        m[3][0] = v.x;
        m[3][1] = v.y;
        m[3][2] = v.z;
    }

    // 0x802C9780 (76 bytes)
    void Scale(EVec3& v) {
        Id();
        m[0][0] = v.x;
        m[1][1] = v.y;
        m[2][2] = v.z;
    }

    // 0x802C97CC (48 bytes)
    float GetScaleX() {
        EVec3 col;
        GetColumn(0, col);
        return EVec3_Length(&col);
    }

    // 0x802C97FC (48 bytes)
    float GetScaleY() {
        EVec3 col;
        GetColumn(1, col);
        return EVec3_Length(&col);
    }

    // 0x802C982C (48 bytes)
    float GetScaleZ() {
        EVec3 col;
        GetColumn(2, col);
        return EVec3_Length(&col);
    }

    // 0x802C985C (108 bytes)
    void RotateX(float angle) {
        Id();
        float s = sinf(angle);
        float c = cosf(angle);
        m[1][1] = c;
        m[2][1] = -s;
        m[1][2] = s;
        m[2][2] = c;
    }

    // 0x802C98C8 (108 bytes)
    void RotateY(float angle) {
        Id();
        float s = sinf(angle);
        float c = cosf(angle);
        m[0][0] = c;
        m[2][0] = -s;
        m[0][2] = s;
        m[2][2] = c;
    }

    // 0x802C9934 (108 bytes)
    void RotateZ(float angle) {
        Id();
        float s = sinf(angle);
        float c = cosf(angle);
        m[0][0] = c;
        m[1][0] = -s;
        m[0][1] = s;
        m[1][1] = c;
    }

    // 0x802CA2D4 (56 bytes)
    void PostTranslate(EVec3& v) {
        m[3][0] += v.x;
        m[3][1] += v.y;
        m[3][2] += v.z;
    }

    // 0x802CA30C (200 bytes)
    // Scales each column of the full 4x4 by the corresponding component
    void PostScale(EVec3& v) {
        m[0][0] *= v.x; m[1][0] *= v.x; m[2][0] *= v.x; m[3][0] *= v.x;
        m[0][1] *= v.y; m[1][1] *= v.y; m[2][1] *= v.y; m[3][1] *= v.y;
        m[0][2] *= v.z; m[1][2] *= v.z; m[2][2] *= v.z; m[3][2] *= v.z;
    }

    // 0x802CA3D4 (56 bytes)
    void PostScale(float scale) {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                m[row][col] *= scale;
            }
        }
    }

    // 0x802CA5DC (100 bytes)
    // Clamps all 16 matrix elements to [-1.0, 1.0]
    void Clamp() {
        for (int row = 0; row <= 3; row++) {
            for (int col = 0; col < 4; col++) {
                float val = m[row][col];
                if (val < -1.0f) {
                    m[row][col] = -1.0f;
                } else if (val > 1.0f) {
                    m[row][col] = 1.0f;
                }
            }
        }
    }

    // 0x802CA640 (4 bytes) - empty in release
    void Print() const {}

    // 0x802CA644 (88 bytes)
    float GetMaxScale() const {
        float maxScale = 0.0f;
        for (int col = 0; col <= 2; col++) {
            float sum = 0.0f;
            for (int row = 0; row < 3; row++) {
                sum += fabsf(m[row][col]);
            }
            if (sum > maxScale) {
                maxScale = sum;
            }
        }
        return maxScale;
    }

    // 0x802CA69C (132 bytes)
    void GetHPR(float& heading, float& pitch, float& roll) {
        heading = atan2f(m[2][2], m[2][0]);
        float len = sqrtf(m[2][0] * m[2][0] + m[2][2] * m[2][2]);
        pitch = -atan2f(m[2][1], len);
        roll = -atan2f(-m[0][1], m[1][1]);
    }

    // 0x802CA720 (64 bytes)
    void ExtractAxisRotation(EVec3& axis) const {
        EQuat quat;
        EQuat_ToMat4(&quat, (EMat4*)this);
        EQuat_ExtractAxisAngle(&quat, &axis);
    }

    // 0x802CA590 (76 bytes)
    void OrientPosNormal(EVec3& pos, EVec3& unused, EVec3& normal) {
        LookAtDirect(pos, normal, 1.0f);
        PostTranslate(pos);
    }

    // 0x8039D348 (136 bytes)
    EMat4& operator=(EMat4& other) {
        m[0][0] = other.m[0][0]; m[0][1] = other.m[0][1];
        m[0][2] = other.m[0][2]; m[0][3] = other.m[0][3];
        m[1][0] = other.m[1][0]; m[1][1] = other.m[1][1];
        m[1][2] = other.m[1][2]; m[1][3] = other.m[1][3];
        m[2][0] = other.m[2][0]; m[2][1] = other.m[2][1];
        m[2][2] = other.m[2][2]; m[2][3] = other.m[2][3];
        m[3][0] = other.m[3][0]; m[3][1] = other.m[3][1];
        m[3][2] = other.m[3][2]; m[3][3] = other.m[3][3];
        return *this;
    }

    // Forward-declared for OrientPosNormal (full impl would be in separate TU)
    void LookAtDirect(EVec3& pos, EVec3& dir, float scale);
};


// ############################################################################
//
//  SECTION 8: CTilePt - Isometric Tile Coordinates
//
//  Layout: 3 bytes (s8 m_x, s8 m_y, s8 m_level)
//  Isometric mapping:
//    Row    = m_x + m_y
//    Column = m_x - m_y
//  World conversion: world_x = tile_x * 16 + 8
//
// ############################################################################

struct TilePt {
    int x; // 0x00
    int y; // 0x04
};

struct FTilePt {
    int x; // 0x00 (tile_x * 16 + 8)
    int y; // 0x04 (tile_y * 16 + 8)
};

class CTilePt {
public:
    s8 m_x;     // 0x00
    s8 m_y;     // 0x01
    s8 m_level; // 0x02

    // --- Constructors ---

    // 0x800B45D0 (12 bytes)
    CTilePt() {
        m_level = 0;
    }

    // 0x800B45DC (32 bytes)
    CTilePt(CTilePt& other) {
        m_x = other.m_x;
        m_y = other.m_y;
        m_level = other.m_level;
    }

    // 0x800B463C (60 bytes)
    // Constructs with overflow check: clamps to 0 if value overflows s8
    CTilePt(int x, int y, int level) {
        m_x = (s8)x;
        if ((s8)m_x != x) m_x = 0;
        m_y = (s8)y;
        if ((s8)m_y != y) m_y = 0;
        m_level = (s8)level;
    }

    // --- Assignment ---

    // 0x800B474C (32 bytes)
    CTilePt& operator=(CTilePt& other) {
        m_x = other.m_x;
        m_y = other.m_y;
        m_level = other.m_level;
        return *this;
    }

    // --- Comparison ---

    // 0x800B476C (48 bytes) - compares x and y only (NOT level)
    bool operator==(CTilePt& other) const {
        if (m_x != other.m_x) return false;
        return m_y == other.m_y;
    }

    // 0x800B479C (48 bytes)
    bool operator!=(CTilePt& other) const {
        if (m_x != other.m_x) return true;
        return m_y != other.m_y;
    }

    // 0x800B47CC (68 bytes) - lexicographic: x first, then y
    bool operator<(CTilePt& other) const {
        if ((s8)m_x < (s8)other.m_x) return true;
        if ((s8)m_x > (s8)other.m_x) return false;
        return (s8)m_y < (s8)other.m_y;
    }

    // --- Arithmetic ---

    // 0x800B4810 (40 bytes)
    CTilePt& operator+=(CTilePt& other) {
        m_x = m_x + other.m_x;
        m_y = m_y + other.m_y;
        return *this;
    }

    // 0x800B4838 (40 bytes)
    CTilePt& operator-=(CTilePt& other) {
        m_x = m_x - other.m_x;
        m_y = m_y - other.m_y;
        return *this;
    }

    // 0x800B4860 (40 bytes)
    CTilePt& operator*=(int s) {
        m_x = (s8)((s8)m_x * s);
        m_y = (s8)((s8)m_y * s);
        return *this;
    }

    // 0x800B4888 (80 bytes)
    CTilePt operator*(int s) const {
        CTilePt result;
        result.m_x = (s8)((s8)m_x * s);
        result.m_y = (s8)((s8)m_y * s);
        result.m_level = m_level;
        return result;
    }

    // 0x800B48D8 (96 bytes)
    CTilePt operator+(CTilePt& other) const {
        CTilePt result;
        result.m_x = (s8)((s8)m_x + (s8)other.m_x);
        result.m_y = (s8)((s8)m_y + (s8)other.m_y);
        result.m_level = m_level;
        return result;
    }

    // 0x800B4938 (96 bytes)
    CTilePt operator-(CTilePt& other) const {
        CTilePt result;
        result.m_x = (s8)((s8)m_x - (s8)other.m_x);
        result.m_y = (s8)((s8)m_y - (s8)other.m_y);
        result.m_level = m_level;
        return result;
    }

    // --- Accessors ---

    // 0x800B4CA8 (12 bytes)
    int GetX() const { return (s8)m_x; }

    // 0x800B4CB4 (12 bytes)
    int GetY() const { return (s8)m_y; }

    // 0x800B4DDC (12 bytes)
    int GetLevel() const { return (s8)m_level; }

    // 0x800B4D04 (12 bytes)
    void SetX(int x) { m_x = (s8)x; }

    // 0x800B4D10 (12 bytes)
    void SetY(int y) { m_y = (s8)y; }

    // 0x800B4DE8 (8 bytes)
    void SetLevel(int level) { m_level = (s8)level; }

    // 0x800B4DF0 (12 bytes)
    void SetLevel(CTilePt& other) { m_level = other.m_level; }

    // 0x800B4D1C (12 bytes)
    void Set(int x, int y) {
        m_y = (s8)y;
        m_x = (s8)x;
    }

    // 0x800B4D28 (16 bytes)
    void Set(int x, int y, int level) {
        m_level = (s8)level;
        m_x = (s8)x;
        m_y = (s8)y;
    }

    // 0x800B4CC0 (28 bytes)
    void Get(int* outX, int* outY) const {
        *outX = (s8)m_x;
        *outY = (s8)m_y;
    }

    // 0x800B4CDC (40 bytes)
    void Get(int* outX, int* outY, int* outLevel) const {
        *outX = (s8)m_x;
        *outY = (s8)m_y;
        *outLevel = (s8)m_level;
    }

    // --- Isometric geometry ---

    // 0x800B49EC (24 bytes)
    int GetRow() const { return (s8)m_x + (s8)m_y; }

    // 0x800B4A04 (24 bytes)
    int GetColumn() const { return (s8)m_x - (s8)m_y; }

    // 0x800B4A98 (68 bytes)
    bool IsNorthOf(CTilePt& other) const {
        return GetRow() < other.GetRow();
    }

    // 0x800B4ADC (68 bytes)
    bool IsSouthOf(CTilePt& other) const {
        return GetRow() > other.GetRow();
    }

    // 0x800B4B20 (68 bytes)
    bool IsWestOf(CTilePt& other) const {
        return GetColumn() < other.GetColumn();
    }

    // 0x800B4B64 (68 bytes)
    bool IsEastOf(CTilePt& other) const {
        return GetColumn() > other.GetColumn();
    }

    // 0x800B4A1C (124 bytes)
    bool IsoCompare(CTilePt& other) const {
        int thisRow = GetRow();
        int otherRow = other.GetRow();
        if (thisRow != otherRow) {
            return thisRow < otherRow;
        }
        int thisCol = GetColumn();
        int otherCol = other.GetColumn();
        return thisCol < otherCol;
    }

    // 0x800B4BA8 (76 bytes)
    bool SameRowParity(CTilePt& other) const {
        return (GetRow() & 1) == (other.GetRow() & 1);
    }

    // 0x800B4BF4 (76 bytes)
    bool SameColumnParity(CTilePt& other) const {
        return (GetColumn() & 1) == (other.GetColumn() & 1);
    }

    // --- Conversions ---

    // 0x800B4C40 (32 bytes)
    TilePt ToTilePt() const {
        TilePt tp;
        tp.x = (s8)m_x;
        tp.y = (s8)m_y;
        return tp;
    }

    // 0x800B4C60 (72 bytes)
    // Converts to fixed-point: value = tile * 16 + 8 (center of tile)
    FTilePt ToFTilePt() const {
        FTilePt ftp;
        int ix = (s8)m_x;
        int iy = (s8)m_y;
        ftp.x = (ix << 4) | 8;
        ftp.y = (iy << 4) | 8;
        return ftp;
    }

    // 0x800B4560 (56 bytes)
    float GetXf() const { return (float)(s8)m_x; }

    // 0x800B4598 (56 bytes)
    float GetYf() const { return (float)(s8)m_y; }
};


// ############################################################################
//
//  SECTION 9: EController - GameCube Input Controller
//
//  Manages button states, analog sticks, vibration motors, and command
//  mapping for a single GameCube controller.
//
//  Layout: 524 bytes (0x20C)
//
// ############################################################################

class EController {
public:
    u32 m_id;                  // 0x000 - controller ID
    u32 m_status;              // 0x004 - status flags (bit 1 = stable)
    u8  m_filterButtonData[0x184]; // 0x008 - filter/button state arrays
    int m_axesSwapped[4];      // 0x18C - per-stick axis swap toggle
    int m_dirModifier[2][2];   // 0x19C - direction inversion per axis [stick][axis]
    // NON_MATCHING: offsets 0x194 vs 0x19C depend on alignment; using
    // field layout from decomp doc: offset 0x194 for dirModifier
    EBtnToCmdAssoc* m_commandMap;  // 0x1A4
    int m_commandMapCount;         // 0x1A8
    u32 m_field_1AC;           // 0x1AC - fake control flag
    u32 m_field_1B0;           // 0x1B0 - fake buttons mask
    u8  m_autoRepeatData[0x28]; // 0x1B4 - auto-repeat state
    float m_motorOneStrength;  // 0x1DC
    float m_motorTwoStrength;  // 0x1E0
    float m_motorOneDuration;  // 0x1E4
    float m_motorTwoDuration;  // 0x1E8
    float m_pausedMotorOne;    // 0x1EC
    float m_pausedMotorTwo;    // 0x1F0
    float m_pausedDurOne;      // 0x1F4
    float m_pausedDurTwo;      // 0x1F8
    u32 m_eventCount;          // 0x1FC
    u32 m_btnExcl;             // 0x200
    u32 m_flags;               // 0x204
    u32 m_pauseFlags;          // 0x208

    // 0x8030588C (8 bytes)
    unsigned int GetId() {
        return m_id;
    }

    // 0x80305894 (8 bytes)
    unsigned int GetStatus() {
        return m_status;
    }

    // 0x8030589C (12 bytes)
    bool IsStable() {
        return (m_status >> 1) & 1;
    }

    // 0x80304294 (8 bytes)
    void OverrideStatus(int status) {
        m_status = status;
    }

    // 0x80304D10 (8 bytes)
    bool IsControlFake() {
        return m_field_1AC != 0;
    }

    // 0x80304D18 (8 bytes)
    void SetControlFake(bool fake) {
        m_field_1AC = fake;
    }

    // 0x80304D20 (8 bytes)
    void SetFakeButtons(unsigned int mask) {
        m_field_1B0 = mask;
    }

    // 0x80304434 (8 bytes) - NGC build: no rumble
    bool HasVibration() const {
        return false;
    }

    // 0x8030429C (24 bytes)
    void SwapAxes(int stick) {
        m_axesSwapped[stick] ^= 1;
    }

    // 0x803042B4 (32 bytes)
    void InvertAxis(int axis, int stick) {
        m_dirModifier[stick][axis] = -m_dirModifier[stick][axis];
    }

    // 0x80305D58 (16 bytes)
    int AreAxesSwapped(int stick) {
        return m_axesSwapped[stick];
    }

    // 0x80305D68 (24 bytes)
    int GetDirectionModifier(int axis, int stick) {
        return m_dirModifier[stick][axis];
    }

    // 0x80305880 (8 bytes)
    // Returns whether motor one is currently active
    bool IsMotorOneActive() {
        return m_motorOneDuration > 0.0f;
    }

    // Returns whether motor two is currently active
    bool IsMotorTwoActive() {
        return m_motorTwoDuration > 0.0f;
    }

    // 0x803038xx - VibrateMotorOne (sets strength and duration)
    void VibrateMotorOne(float strength) {
        m_motorOneStrength = strength;
        m_motorOneDuration = -1.0f; // -1 = infinite duration
    }

    void VibrateMotorOne(float strength, float duration) {
        m_motorOneStrength = strength;
        m_motorOneDuration = duration;
    }

    void VibrateMotorTwo(float strength) {
        m_motorTwoStrength = strength;
        m_motorTwoDuration = -1.0f;
    }

    void VibrateMotorTwo(float strength, float duration) {
        m_motorTwoStrength = strength;
        m_motorTwoDuration = duration;
    }

    void StopMotorOne() {
        m_motorOneStrength = 0.0f;
        m_motorOneDuration = 0.0f;
    }

    void StopMotorTwo() {
        m_motorTwoStrength = 0.0f;
        m_motorTwoDuration = 0.0f;
    }

    void StopVibration() {
        StopMotorOne();
        StopMotorTwo();
    }

    // 0x803041xx - PauseMotors / ResumeMotors
    void PauseMotors() {
        m_pausedMotorOne = m_motorOneStrength;
        m_pausedMotorTwo = m_motorTwoStrength;
        m_pausedDurOne = m_motorOneDuration;
        m_pausedDurTwo = m_motorTwoDuration;
        StopVibration();
    }

    void ResumeMotors() {
        m_motorOneStrength = m_pausedMotorOne;
        m_motorTwoStrength = m_pausedMotorTwo;
        m_motorOneDuration = m_pausedDurOne;
        m_motorTwoDuration = m_pausedDurTwo;
    }

    // SetCommandMap - installs button-to-command mapping table
    void SetCommandMap(EBtnToCmdAssoc* map, int count) {
        m_commandMap = map;
        m_commandMapCount = count;
    }
};


// ############################################################################
//
//  SECTION 10: EControllerManager - Multi-Controller Management
//
//  Manages up to 4 controllers and player-to-controller mappings.
//
// ############################################################################

class EControllerManager {
public:
    u32 m_controllerIndex[4];  // 0x00 - which controller each player uses
    u32 m_playerMapped[4];     // 0x10 - is player mapped (0/1)
    // Controller objects follow at 0x20+

    // 0x80323AF0 (8 bytes) - hardcoded for GameCube
    int GetControllerCount() {
        return 4;
    }

    // 0x8032344C (4 bytes)
    void Shutdown() {
        // empty stub
    }

    // 0x80323450 (24 bytes)
    void MapPlayerToController(unsigned int player, unsigned int controller) {
        m_controllerIndex[player] = controller;
        m_playerMapped[player] = 1;
    }

    // 0x803235CC (20 bytes)
    void UnmapPlayer(unsigned int player) {
        m_playerMapped[player] = 0;
    }

    // 0x803235E0 (16 bytes)
    unsigned int GetPlayerMapped(unsigned int player) {
        return m_playerMapped[player];
    }

    // 0x80323610 (28 bytes)
    int GetPlayerControllerIndex(unsigned int player) {
        if (player > 3) return -1;
        return m_controllerIndex[player];
    }

    // 0x80324534 (12 bytes)
    unsigned int IndexToBit(int index) {
        return 1 << index;
    }
};


// ############################################################################
//
//  SECTION 11: EVec3Decomp - Compressed Vector Decompression
//
// ############################################################################

class EBitArray;

class EVec3Decomp {
public:
    u8  pad00[0x18];       // 0x00 - internal state
    int m_numComponents;   // 0x18
    s16 m_bitsPerComp;     // 0x1C
    // additional fields follow...

    // 0x802D6010 (20 bytes)
    int GetBitCount() {
        return m_numComponents * m_bitsPerComp + 227;
    }
};
