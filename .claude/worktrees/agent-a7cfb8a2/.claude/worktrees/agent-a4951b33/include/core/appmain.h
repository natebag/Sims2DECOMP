// appmain.h - ESimsApp, STL containers, and TArray specializations from appmain.obj
// Contains: _Base_bitset<3>, _Deque_base<StateMachineStatus*>, __node_alloc<false,0>,
//           TArray specializations for EVec3, ENLatticePoints, ENDummyPoint, ENCameraPoint

#ifndef APPMAIN_H
#define APPMAIN_H

#include "types.h"
#include "core/e_vec3.h"

// Forward declarations
class EStream;
class EAHeap;
class StateMachineStatus;

// ============================================================================
// ENLatticePoints - Lattice point for camera/navigation system
// Size: 0x0C (12 bytes) - same size as EVec3 based on TArray stride
// ============================================================================
struct ENLatticePoints {
    float x; // 0x00
    float y; // 0x04
    float z; // 0x08
};

// ============================================================================
// ENDummyPoint - Dummy point for camera/navigation system
// Size: unknown but TArray::Copy uses assignment operator copy loop
// ============================================================================
struct ENDummyPoint {
    u8 data[12]; // placeholder - exact layout TBD from further RE
};

// ============================================================================
// ENCameraPoint - Camera point for camera system
// Size: unknown but TArray::Copy uses assignment operator copy loop
// ============================================================================
struct ENCameraPoint {
    u8 data[12]; // placeholder - exact layout TBD from further RE
};

// ============================================================================
// TArrayDefaultAllocator - default allocator tag
// ============================================================================
struct TArrayDefaultAllocator;

// ============================================================================
// TArrayERCharacterAllocator - ER character allocator tag
// ============================================================================
struct TArrayERCharacterAllocator;

// ============================================================================
// TArray template forward declaration
// ============================================================================
template <class T, class Alloc>
class TArray;

// ============================================================================
// _Base_bitset<3> - SGI STL bitset base (3 words = 96 bits)
// ============================================================================
template <int N>
struct _Base_bitset {
    unsigned int _M_w[N]; // word array

    unsigned int _M_do_find_first(unsigned int __not_found) const;
};

// ============================================================================
// __node_alloc<false, 0> - SGI STL node allocator (single-threaded)
// Uses a free list array indexed by size class
// ============================================================================
template <bool threads, int inst>
class __node_alloc {
public:
    static void* _S_free_list[8]; // 8 size classes, at 0x8045a8b0

    static void _M_deallocate(void* __p, unsigned int __n);
    static void* _M_allocate(unsigned int __n);
    static char* _S_chunk_alloc(unsigned int __size, int& __nobjs);
    static void* _S_refill(unsigned int __n);
};

// ============================================================================
// _Deque_base<StateMachineStatus*, allocator<StateMachineStatus*>>
// SGI STL deque implementation base
// Layout:
//   0x00: _M_map (StateMachineStatus***)
//   0x04: _M_map_size (unsigned int)
//   0x08: _M_start._M_first
//   0x0C: _M_start._M_last
//   0x10: _M_start._M_cur
//   0x14: _M_start._M_node
//   0x18: _M_finish._M_first
//   0x1C: _M_finish._M_last
//   0x20: _M_finish._M_cur
//   0x24: _M_finish._M_node
//   0x28: (additional allocator state)
//   0x2C: _M_map_size_alloc
// ============================================================================
template <class T, class Alloc>
class _Deque_base {
public:
    // Deque map and iterators (0x30 bytes total layout)
    T** m_map;                  // 0x00 - map of node pointers
    // ... iterator state ...
    char _pad04[0x20];          // 0x04
    T** m_mapAlloc;             // 0x24
    unsigned int m_mapSize;     // 0x28
    unsigned int m_mapSizeAlloc;// 0x2C

    void _M_create_nodes(T** __nstart, T** __nfinish);
    void _M_destroy_nodes(T** __nstart, T** __nfinish);
    void _M_initialize_map(unsigned int __num_elements);
    ~_Deque_base(void);
};

// ============================================================================
// _Bs_G<bool> - Bitset global lookup tables
// ============================================================================
template <bool dummy>
struct _Bs_G {
    static unsigned char _S_bit_count[256]; // at 0x8045a8f0
    static unsigned char _S_first_one[256]; // at 0x8045a9f0
};

// ============================================================================
// TArray<int, TArrayERCharacterAllocator>
// ============================================================================
template <>
class TArray<int, TArrayERCharacterAllocator> {
public:
    int* m_data;    // 0x00
    int m_size;     // 0x04
    int m_capacity; // 0x08

    void Destruct(int* ptr, int count);
    void Init(void);
    void Construct(int* dst, int count);
    void Copy(int* dst, int* src, int count);
    void SetSize(int newSize, int growBy);
};

// ============================================================================
// TArray<EVec3, TArrayDefaultAllocator>
// ============================================================================
template <>
class TArray<EVec3, TArrayDefaultAllocator> {
public:
    EVec3* m_data;  // 0x00
    int m_size;     // 0x04
    int m_capacity; // 0x08

    void Destruct(EVec3* ptr, int count);
    void Init(void);
    void Deallocate(void);
    void Construct(EVec3* dst, int count);
    void Copy(EVec3* dst, EVec3* src, int count);
    void SetSize(int newSize, int growBy);
    TArray<EVec3, TArrayDefaultAllocator>& operator=(TArray<EVec3, TArrayDefaultAllocator>& other);

    TArray(void);
    TArray(TArray<EVec3, TArrayDefaultAllocator>& other);
    ~TArray(void);
};

// ============================================================================
// TArray<ENLatticePoints, TArrayDefaultAllocator>
// ============================================================================
template <>
class TArray<ENLatticePoints, TArrayDefaultAllocator> {
public:
    ENLatticePoints* m_data;  // 0x00
    int m_size;               // 0x04
    int m_capacity;           // 0x08

    void Destruct(ENLatticePoints* ptr, int count);
    void Init(void);
    void Construct(ENLatticePoints* dst, int count);
    void Copy(ENLatticePoints* dst, ENLatticePoints* src, int count);
    void SetSize(int newSize, int growBy);
};

// ============================================================================
// TArray<ENDummyPoint, TArrayDefaultAllocator>
// ============================================================================
template <>
class TArray<ENDummyPoint, TArrayDefaultAllocator> {
public:
    ENDummyPoint* m_data;  // 0x00
    int m_size;            // 0x04
    int m_capacity;        // 0x08

    void Destruct(ENDummyPoint* ptr, int count);
    void Init(void);
    void Construct(ENDummyPoint* dst, int count);
    void Copy(ENDummyPoint* dst, ENDummyPoint* src, int count);
    void SetSize(int newSize, int growBy);
};

// ============================================================================
// TArray<ENCameraPoint, TArrayDefaultAllocator>
// ============================================================================
template <>
class TArray<ENCameraPoint, TArrayDefaultAllocator> {
public:
    ENCameraPoint* m_data;  // 0x00
    int m_size;             // 0x04
    int m_capacity;         // 0x08

    void Destruct(ENCameraPoint* ptr, int count);
    void Init(void);
    void Construct(ENCameraPoint* dst, int count);
    void Copy(ENCameraPoint* dst, ENCameraPoint* src, int count);
    void SetSize(int newSize, int growBy);
};

// Stream operators for TArray<int, TArrayERCharacterAllocator>
EStream& operator<<(EStream& stream, TArray<int, TArrayERCharacterAllocator>& arr);
EStream& operator>>(EStream& stream, TArray<int, TArrayERCharacterAllocator>& arr);

// StateMachineState::SetFlag
class StateMachineState;

#endif // APPMAIN_H
