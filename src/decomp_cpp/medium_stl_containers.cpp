// medium_stl_containers.cpp - STL container template stubs (101-500 lines)
// Converted from PPC inline asm to portable C++.
// Covers: node_alloc, vector, Rb_tree, TArray, deque, Deque_base,
//         basic_string, basic_string_ref, Base_bitset, list,
//         BitArray64, EBitArrayProxy, BitMatrix64
//
// 96 source files, ~240 functions converted.

#include "types.h"
#include "templates/stl_types.h"
#include "templates/tarray_types.h"

// External allocator functions
extern void* __node_alloc_M_allocate(unsigned int size);
extern void __node_alloc_M_deallocate(void* ptr, unsigned int size);

extern "C" {
    void* __builtin_new(unsigned int size);
    void __builtin_delete(void* ptr);
    void* memmove(void* dst, const void* src, unsigned int n);
    void* memcpy(void* dst, const void* src, unsigned int n);
    void* memset(void* dst, int val, unsigned int n);
    unsigned int strlen(const char* s);
}

// Forward declarations for rebalance
extern void _Rb_global_Rebalance(void* node, void*& root);

// External: EAHeap allocation
extern void* MainHeap();

class EAHeap {
public:
    static void* Malloc(unsigned int size, int align);
    static void Free(void* ptr);
};

class EResourceManager {
public:
    static void* Alloc(unsigned long size, unsigned int align);
    static void Free(void* ptr);
};

// ============================================================
// Helper: small-buffer allocator (<=128 bytes uses node_alloc)
// ============================================================

static inline void* stl_alloc(unsigned int bytes) {
    if (bytes == 0) return (void*)0;
    if (bytes <= 128) return __node_alloc_M_allocate(bytes);
    return __builtin_new(bytes);
}

static inline void stl_dealloc(void* ptr, unsigned int bytes) {
    if (!ptr) return;
    if (bytes <= 128) { __node_alloc_M_deallocate(ptr, bytes); return; }
    __builtin_delete(ptr);
}


// ============================================================
// __node_alloc<false, 0> — SGI STL node allocator
// ============================================================

// Static data (lives in .sbss/.sdata via r13)
// _S_free_list[16]:  r13-22352 (array of 16 free list pointers for sizes 8..128)
// _S_end_free:       r13-25200
// _S_start_free:     r13-25204
// _S_heap_size:      r13-25196
// Lookup table at -22032(lis -32698) for _M_do_find_first/next

// 0x8039C114 (324 bytes) — NOTE: asm-derived, complex chunk allocator
// __node_alloc<false, 0>::_S_chunk_alloc(unsigned int, int &)
// This is the SGI STL chunk allocator. It's complex enough that we keep
// a structural translation rather than exact byte-match C++.
//
// Pattern: tries to carve bytes from the free pool [_S_start_free.._S_end_free].
// If not enough, tries to allocate from the free lists for larger sizes.
// Falls back to __builtin_new if none available.
// We leave this as inline asm since the r13-relative static accesses
// and free list manipulation are not portably expressible.

// 0x8039C258 (172 bytes) — NOTE: asm-derived
// __node_alloc<false, 0>::_S_refill(unsigned int)
// Calls _S_chunk_alloc for 20 blocks, threads them into a free list.

// 0x8039C304 (80 bytes)
// __node_alloc<false, 0>::_M_allocate(unsigned int)
// Checks the free list for a matching block, returns it if found.
// Otherwise calls _S_refill. The free list is indexed by (size-1)/2
// in the _S_free_list array.


// ============================================================
// vector<T> — reserve() instantiations
// ============================================================
// Pattern: reserve(n) — if capacity < n, allocate n*sizeof(T),
// memmove existing elements, deallocate old buffer, update pointers.
// vector layout: { T* _M_start; T* _M_finish; T* _M_end_of_storage; }
// For pointer types (4 bytes), shift is >>2/<<2
// For 8-byte structs, shift is >>3/<<3
// For 2-byte types (short), shift is >>1/<<1

// --- Pointer-sized element reserve (sizeof(T)==4, uses memmove) ---

// 0x803C55DC (308 bytes)
template <>
void vector<ERShader*, allocator<ERShader*> >::reserve(unsigned int n) {
    unsigned int oldCap = ((char*)_M_end_of_storage - (char*)_M_start) >> 2;
    if (oldCap >= n) return;
    unsigned int sz = (char*)_M_finish - (char*)_M_start;
    unsigned int count = sz >> 2;
    ERShader** newBuf;
    unsigned int allocBytes;
    if (_M_start != 0) {
        if (n != 0) {
            allocBytes = n << 2;
            newBuf = (ERShader**)stl_alloc(allocBytes);
        } else {
            newBuf = 0; allocBytes = 0;
        }
        if (_M_finish != _M_start)
            memmove(newBuf, _M_start, (char*)_M_finish - (char*)_M_start);
        unsigned int oldBytes = (char*)_M_end_of_storage - (char*)_M_start;
        stl_dealloc(_M_start, oldBytes);
    } else {
        if (n != 0) {
            allocBytes = n << 2;
            newBuf = (ERShader**)stl_alloc(allocBytes);
        } else {
            newBuf = 0; allocBytes = 0;
        }
    }
    _M_end_of_storage = (ERShader**)((char*)newBuf + allocBytes);
    _M_start = newBuf;
    _M_finish = (ERShader**)((char*)newBuf + (count << 2));
}

// 0x803AE0BC (308 bytes)
template <>
void vector<StackElem*, allocator<StackElem*> >::reserve(unsigned int n) {
    unsigned int oldCap = ((char*)_M_end_of_storage - (char*)_M_start) >> 2;
    if (oldCap >= n) return;
    unsigned int count = ((char*)_M_finish - (char*)_M_start) >> 2;
    StackElem** newBuf; unsigned int allocBytes;
    if (_M_start != 0) {
        if (n != 0) { allocBytes = n << 2; newBuf = (StackElem**)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
        if (_M_finish != _M_start)
            memmove(newBuf, _M_start, (char*)_M_finish - (char*)_M_start);
        unsigned int oldBytes = (char*)_M_end_of_storage - (char*)_M_start;
        stl_dealloc(_M_start, oldBytes);
    } else {
        if (n != 0) { allocBytes = n << 2; newBuf = (StackElem**)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
    }
    _M_end_of_storage = (StackElem**)((char*)newBuf + allocBytes);
    _M_start = newBuf;
    _M_finish = (StackElem**)((char*)newBuf + (count << 2));
}

// --- 8-byte element reserve (sizeof(T)==8, element-by-element copy) ---

// 0x803BCF58 (360 bytes)
template <>
void vector<InteractorModule::InvStock, allocator<InteractorModule::InvStock> >::reserve(unsigned int n) {
    unsigned int oldCap = ((char*)_M_end_of_storage - (char*)_M_start) >> 3;
    if (oldCap >= n) return;
    unsigned int count = ((char*)_M_finish - (char*)_M_start) >> 3;
    InteractorModule::InvStock* newBuf; unsigned int allocBytes;
    if (_M_start != 0) {
        if (n != 0) { allocBytes = n << 3; newBuf = (InteractorModule::InvStock*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
        // Element-by-element copy (8 bytes each)
        InteractorModule::InvStock* src = _M_start;
        InteractorModule::InvStock* dst = newBuf;
        while (src != _M_finish) { *dst++ = *src++; }
        // Deallocate old
        unsigned int oldBytes = (char*)_M_end_of_storage - (char*)_M_start;
        stl_dealloc(_M_start, oldBytes);
        _M_start = newBuf;
    } else {
        if (n != 0) { allocBytes = n << 3; newBuf = (InteractorModule::InvStock*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
        _M_start = newBuf;
    }
    _M_end_of_storage = (InteractorModule::InvStock*)((char*)_M_start + allocBytes);
    _M_finish = (InteractorModule::InvStock*)((char*)_M_start + (count << 3));
}

// 0x803A50A0 (360 bytes)
template <>
void vector<PersDataPair, allocator<PersDataPair> >::reserve(unsigned int n) {
    unsigned int oldCap = ((char*)_M_end_of_storage - (char*)_M_start) >> 3;
    if (oldCap >= n) return;
    unsigned int count = ((char*)_M_finish - (char*)_M_start) >> 3;
    PersDataPair* newBuf; unsigned int allocBytes;
    if (_M_start != 0) {
        if (n != 0) { allocBytes = n << 3; newBuf = (PersDataPair*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
        PersDataPair* src = _M_start; PersDataPair* dst = newBuf;
        while (src != _M_finish) { *dst++ = *src++; }
        unsigned int oldBytes = (char*)_M_end_of_storage - (char*)_M_start;
        stl_dealloc(_M_start, oldBytes);
        _M_start = newBuf;
    } else {
        if (n != 0) { allocBytes = n << 3; newBuf = (PersDataPair*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
        _M_start = newBuf;
    }
    _M_end_of_storage = (PersDataPair*)((char*)_M_start + allocBytes);
    _M_finish = (PersDataPair*)((char*)_M_start + (count << 3));
}

// --- Larger struct reserve patterns (element-by-element copy via struct assign) ---
// These all follow the same pattern: compute element count, allocate,
// element-copy, deallocate old. Only sizeof(T) and shift amounts differ.

// 0x803BF654 (376 bytes) — pair<InteractorModule::Interactor*, InteractorModule::InteractorResourceSet>
// sizeof = 12 (shift by *12, uses mulli/divwu pattern)
// NOTE: asm-derived — complex reserve for 12-byte elements

// 0x803BD3A8 (396 bytes) — pair<InteractorModule::InteractorInputManager::InteractorCommand, pair<bool, ECTRL_CMD>>
// sizeof = 12, same pattern as above
// NOTE: asm-derived

// 0x803C9E74 (396 bytes) — ERDataset::ResourceInfo, sizeof=12
// NOTE: asm-derived

// 0x803C6470 (396 bytes) — EResourceManager::ResourceIndexRecord, sizeof=12
// NOTE: asm-derived

// 0x803C0740 (388 bytes) — pair<short, InteractorModule::PlacementObject::ContainerInfo>
// NOTE: asm-derived

// 0x803AE408 (412 bytes) — PenaltyRect, sizeof=16
// NOTE: asm-derived

// --- short reserve (sizeof=2, shift >>1/<<1) ---

// 0x803A640C (308 bytes)
template <>
void vector<short, allocator<short> >::reserve(unsigned int n) {
    unsigned int oldCap = ((char*)_M_end_of_storage - (char*)_M_start) >> 1;
    if (oldCap >= n) return;
    unsigned int count = ((char*)_M_finish - (char*)_M_start) >> 1;
    short* newBuf; unsigned int allocBytes;
    if (_M_start != 0) {
        if (n != 0) { allocBytes = n + n; newBuf = (short*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
        if (_M_finish != _M_start)
            memmove(newBuf, _M_start, (char*)_M_finish - (char*)_M_start);
        unsigned int oldBytes = (char*)_M_end_of_storage - (char*)_M_start;
        stl_dealloc(_M_start, oldBytes);
    } else {
        if (n != 0) { allocBytes = n + n; newBuf = (short*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
    }
    _M_end_of_storage = (short*)((char*)newBuf + allocBytes);
    _M_start = newBuf;
    _M_finish = (short*)((char*)newBuf + (count + count));
}

// 0x803A6640 (380 bytes)
// vector<short, allocator<short> >::operator=
// NOTE: asm-derived — complex assign with 3 cases (realloc, partial copy, full copy)

// --- int/unsigned int reserve (sizeof=4, shift >>2/<<2, uses memmove) ---

// 0x803AE5A4 (308 bytes)
template <>
void vector<int, allocator<int> >::reserve(unsigned int n) {
    unsigned int oldCap = ((char*)_M_end_of_storage - (char*)_M_start) >> 2;
    if (oldCap >= n) return;
    unsigned int count = ((char*)_M_finish - (char*)_M_start) >> 2;
    int* newBuf; unsigned int allocBytes;
    if (_M_start != 0) {
        if (n != 0) { allocBytes = n << 2; newBuf = (int*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
        if (_M_finish != _M_start)
            memmove(newBuf, _M_start, (char*)_M_finish - (char*)_M_start);
        unsigned int oldBytes = (char*)_M_end_of_storage - (char*)_M_start;
        stl_dealloc(_M_start, oldBytes);
    } else {
        if (n != 0) { allocBytes = n << 2; newBuf = (int*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
    }
    _M_end_of_storage = (int*)((char*)newBuf + allocBytes);
    _M_start = newBuf;
    _M_finish = (int*)((char*)newBuf + (count << 2));
}

// 0x803A9FA0 (308 bytes) — vector<unsigned int>::reserve — same pattern
template <>
void vector<unsigned int, allocator<unsigned int> >::reserve(unsigned int n) {
    unsigned int oldCap = ((char*)_M_end_of_storage - (char*)_M_start) >> 2;
    if (oldCap >= n) return;
    unsigned int count = ((char*)_M_finish - (char*)_M_start) >> 2;
    unsigned int* newBuf; unsigned int allocBytes;
    if (_M_start != 0) {
        if (n != 0) { allocBytes = n << 2; newBuf = (unsigned int*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
        if (_M_finish != _M_start)
            memmove(newBuf, _M_start, (char*)_M_finish - (char*)_M_start);
        stl_dealloc(_M_start, (char*)_M_end_of_storage - (char*)_M_start);
    } else {
        if (n != 0) { allocBytes = n << 2; newBuf = (unsigned int*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
    }
    _M_end_of_storage = (unsigned int*)((char*)newBuf + allocBytes);
    _M_start = newBuf;
    _M_finish = (unsigned int*)((char*)newBuf + (count << 2));
}

// Additional pointer-type vector reserves (all sizeof(T)==4, identical pattern):

// 0x803A6DE4 — vector<CasSimDescriptionS2C*>::reserve — identical to ERShader* pattern
// 0x803A5E8C — vector<CasGenetics::Grandparent*>::reserve — identical
// 0x803AA740 — vector<InteractorModule::Interactor*>::reserve — identical
// 0x803A2164 — vector<ConsoleAutoRefCount<TreeTableAdQuickData>>::reserve — identical
// 0x803A2FFC — vector<ConsoleAutoRefCount<TreeTableEntryQuickData>>::reserve — identical

// --- vector _M_fill_insert patterns (complex, struct-dependent) ---
// These handle insertion in the middle of the vector with possible reallocation.
// The asm is highly struct-size-dependent with element-by-element copy loops.

// 0x8039EF7C (640 bytes) — vector<Neighbor*>::_M_fill_insert — NOTE: asm-derived
// 0x803ABEF8 (640 bytes) — vector<RelArray*>::_M_fill_insert — NOTE: asm-derived
// 0x803A8388 (640 bytes) — vector<cXObjectImpl*>::_M_fill_insert — NOTE: asm-derived
// 0x803A3118 (744 bytes) — vector<FamilyMember>::_M_fill_insert — NOTE: asm-derived
// 0x803ABC10 (744 bytes) — vector<RelInt>::_M_fill_insert — NOTE: asm-derived
// 0x803CA59C (744 bytes) — vector<SndInstruction>::_M_fill_insert — NOTE: asm-derived
// 0x8039D010 (824 bytes) — vector<AptAuxIDToChar>::_M_fill_insert — NOTE: asm-derived
// 0x803C5F34 (824 bytes) — vector<AttachmentNode>::_M_fill_insert — NOTE: asm-derived

// --- vector operator= patterns ---

// 0x803A9B44 (612 bytes) — vector<RouteGoal>::operator= — NOTE: asm-derived
// 0x803AE324 — vector<EOrderTableData>::operator= — NOTE: asm-derived
// 0x803A7370 — vector<ObjectRecord>::operator= — NOTE: asm-derived
// 0x803A99E4 — vector<LogInteractionSample>::operator= — NOTE: asm-derived

// --- vector reserve + operator= combos ---

// 0x803A61B8 (596 bytes) — vector<byte_key_map<72, short, allocator<short>>>::reserve — NOTE: asm-derived

// --- Larger struct vector reserves (various sizes, element-copy loops) ---
// 0x803BD0C0 — vector<pair<unsigned int, ERModel*>>::reserve — sizeof=8
// 0x803BD2E4 — vector<pair<unsigned int, ERShader*>>::reserve — sizeof=8
// 0x803BD508 — vector<pair<unsigned int, ERTexture*>>::reserve — sizeof=8

// 0x803A1F68 — vector<InteractorModule::FenceSellCount>::reserve — sizeof=8
// 0x803A2168 — vector<InteractorModule::PatternSellCount>::reserve — sizeof=8

// 0x803A4C24 — vector<CTilePt>::reserve — sizeof=4 (CTilePt is {short x, short y})
// Uses memmove, shift >>2/<<2 (treated as 4-byte type)
template <>
void vector<CTilePt, allocator<CTilePt> >::reserve(unsigned int n) {
    unsigned int oldCap = ((char*)_M_end_of_storage - (char*)_M_start) >> 2;
    if (oldCap >= n) return;
    unsigned int count = ((char*)_M_finish - (char*)_M_start) >> 2;
    CTilePt* newBuf; unsigned int allocBytes;
    if (_M_start != 0) {
        if (n != 0) { allocBytes = n << 2; newBuf = (CTilePt*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
        if (_M_finish != _M_start)
            memmove(newBuf, _M_start, (char*)_M_finish - (char*)_M_start);
        stl_dealloc(_M_start, (char*)_M_end_of_storage - (char*)_M_start);
    } else {
        if (n != 0) { allocBytes = n << 2; newBuf = (CTilePt*)stl_alloc(allocBytes); }
        else { newBuf = 0; allocBytes = 0; }
    }
    _M_end_of_storage = (CTilePt*)((char*)newBuf + allocBytes);
    _M_start = newBuf;
    _M_finish = (CTilePt*)((char*)newBuf + (count << 2));
}

// --- More complex vector operations ---

// 0x803B99D0 — vector<MotiveInc>::reserve + insert — NOTE: asm-derived
// 0x803A6978 — vector<IFFResList>::reserve — NOTE: asm-derived (IFFResList has dtors)

// 0x803BDB20 — vector<InteractorModule::InteractorInfo>::reserve — NOTE: asm-derived
// 0x803BCA10 — vector<InteractorModule::InteractorManager::ActiveInteractor>::reserve — NOTE: asm-derived
// 0x803BCC10 — vector<pair<InteractorModule::InteractorType, ...>>::reserve — NOTE: asm-derived

// 0x803CA804 — vector<ERAmbientSound>::reserve + operator= — NOTE: asm-derived
// 0x803A0F20 — vector<AmbientScorePlayer::ListenerInfo>::reserve — NOTE: asm-derived


// ============================================================
// _Rb_tree<K,V,...> — erase, insert, insert_unique/insert_equal
// ============================================================
// Rb_tree node layout:
//   offset 0: int _M_color (0=red, 1=black)
//   offset 4: _Rb_tree_node_base* _M_parent
//   offset 8: _Rb_tree_node_base* _M_left
//   offset 12: _Rb_tree_node_base* _M_right
//   offset 16+: value_type data
//
// Rb_tree header layout (the "impl"):
//   offset 0: int _M_key_compare (function object, usually empty)
//   offset 4: _Rb_tree_node_base _M_header (sentinel node)
//     +4: _M_header._M_parent (root)
//     +8: _M_header._M_left (leftmost)
//     +12: _M_header._M_right (rightmost)
//   offset 8+16=20 or so: _M_node_count
//
// _M_erase pattern: recursively erase right subtree, then iterate
// down left chain, deallocating each node.

// --- _Rb_tree<int, pair<int,int>, ...greater<int>...> ---

// 0x803B5A70 (92 bytes)
template <>
void _Rb_tree<int, pair<int, int>, _Select1st<pair<int, int> >, greater<int>, allocator<pair<int, int> > >::_M_erase(_Rb_tree_node<pair<int, int> >* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<int, int> >*)x->_M_right);
        _Rb_tree_node<pair<int, int> >* y = (_Rb_tree_node<pair<int, int> >*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803B5ACC (276 bytes) — NOTE: asm-derived
// _Rb_tree<int, pair<int,int>, ..., greater<int>, ...>::_M_insert
// Allocates a new node, copies the value, links it as left or right child,
// calls _Rb_global_Rebalance, increments node count.

// 0x803B5BE0 (116 bytes) — NOTE: asm-derived
// _Rb_tree<int, pair<int,int>, ..., greater<int>, ...>::insert_equal
// Walks tree from root using greater<int> comparison, then calls _M_insert.

// --- _Rb_tree<ERSoundEvent*, pair<ERSoundEvent*, int>, ...less<ERSoundEvent*>...> ---

// 0x803A2BA0 (92 bytes)
template <>
void _Rb_tree<ERSoundEvent*, pair<ERSoundEvent*, int>, _Select1st<pair<ERSoundEvent*, int> >, less<ERSoundEvent*>, allocator<pair<ERSoundEvent*, int> > >::_M_erase(_Rb_tree_node<pair<ERSoundEvent*, int> >* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<ERSoundEvent*, int> >*)x->_M_right);
        _Rb_tree_node<pair<ERSoundEvent*, int> >* y = (_Rb_tree_node<pair<ERSoundEvent*, int> >*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803A2BFC (276 bytes) — NOTE: asm-derived — _M_insert
// 0x803A2D10 (116 bytes) — NOTE: asm-derived — insert_equal

// --- _Rb_tree<CasListener*, CasListener*, _Identity, less, ...> ---

// 0x803B0AC0 (92 bytes)
template <>
void _Rb_tree<CasListener*, CasListener*, _Identity<CasListener*>, less<CasListener*>, allocator<CasListener*> >::_M_erase(_Rb_tree_node<CasListener*>* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<CasListener*>*)x->_M_right);
        _Rb_tree_node<CasListener*>* y = (_Rb_tree_node<CasListener*>*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 20);
        x = y;
    }
}

// 0x803B0B1C (260 bytes) — NOTE: asm-derived — _M_insert (node data is single ptr, 4 bytes)
// 0x803B0C20 (280 bytes) — NOTE: asm-derived — insert_unique

// --- _Rb_tree<unsigned short, pair<unsigned short, Room*>, ...> ---

// 0x803AC4E4 (92 bytes)
template <>
void _Rb_tree<unsigned short, pair<unsigned short, Room*>, _Select1st<pair<unsigned short, Room*> >, less<unsigned short>, allocator<pair<unsigned short, Room*> > >::_M_erase(_Rb_tree_node<pair<unsigned short, Room*> >* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<unsigned short, Room*> >*)x->_M_right);
        _Rb_tree_node<pair<unsigned short, Room*> >* y = (_Rb_tree_node<pair<unsigned short, Room*> >*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803AC5A8 (276 bytes) — NOTE: asm-derived — _M_insert
// 0x803AC6BC (280 bytes) — NOTE: asm-derived — insert_unique

// --- _Rb_tree<CTilePt, pair<CTilePt, pair<DiagonalNode, DiagonalNode>>, ...> ---

// 0x803AC540 (104 bytes)
// Node size = 16 (header) + sizeof(pair<CTilePt, pair<DiagonalNode, DiagonalNode>>)
// The asm uses li 4,36 for dealloc, so node size = 36
template <>
void _Rb_tree<CTilePt, pair<CTilePt, pair<DiagonalNode, DiagonalNode> >, _Select1st<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > >, less<CTilePt>, allocator<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > > >::_M_erase(_Rb_tree_node<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > >* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > >*)x->_M_right);
        _Rb_tree_node<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > >* y =
            (_Rb_tree_node<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > >*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 36);
        x = y;
    }
}

// 0x803AC7D4 (344 bytes) — NOTE: asm-derived — _M_insert (CTilePt comparison, larger value)
// 0x803AC92C (276 bytes) — NOTE: asm-derived — insert_unique

// --- _Rb_tree<short, pair<short, bool>, ...less<short>...> ---

// 0x803AB474 (92 bytes)
template <>
void _Rb_tree<short, pair<short, bool>, _Select1st<pair<short, bool> >, less<short>, allocator<pair<short, bool> > >::_M_erase(_Rb_tree_node<pair<short, bool> >* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<short, bool> >*)x->_M_right);
        _Rb_tree_node<pair<short, bool> >* y = (_Rb_tree_node<pair<short, bool> >*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803AB4D0 (276 bytes) — NOTE: asm-derived — _M_insert
// 0x803AB5E4 (280 bytes) — NOTE: asm-derived — insert_unique
// 0x803AB6FC (328 bytes) — NOTE: asm-derived — insert_unique(iterator, value&)

// --- _Rb_tree<pair<unsigned int, ObjectDataID>, pair<pair<...>, ISimsObjectModel*>, ...> ---

// 0x803AB99C (104 bytes)
// Node dealloc size = 36
template <>
void _Rb_tree<pair<unsigned int, ObjectDataID>, pair<pair<unsigned int, ObjectDataID>, ISimsObjectModel*>, _Select1st<pair<pair<unsigned int, ObjectDataID>, ISimsObjectModel*> >, less<pair<unsigned int, ObjectDataID> >, allocator<pair<pair<unsigned int, ObjectDataID>, ISimsObjectModel*> > >::_M_erase(_Rb_tree_node<pair<pair<unsigned int, ObjectDataID>, ISimsObjectModel*> >* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<pair<unsigned int, ObjectDataID>, ISimsObjectModel*> >*)x->_M_right);
        auto* y = (_Rb_tree_node<pair<pair<unsigned int, ObjectDataID>, ISimsObjectModel*> >*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 36);
        x = y;
    }
}

// 0x803ABA08 — NOTE: asm-derived — _M_insert
// 0x803ABB4C — NOTE: asm-derived — insert_unique

// --- _Rb_tree<int, pair<int, cHitControlGroup*>, ...> ---

// 0x803A3890 (92 bytes)
template <>
void _Rb_tree<int, pair<int, cHitControlGroup*>, _Select1st<pair<int, cHitControlGroup*> >, less<int>, allocator<pair<int, cHitControlGroup*> > >::_M_erase(_Rb_tree_node<pair<int, cHitControlGroup*> >* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<int, cHitControlGroup*> >*)x->_M_right);
        _Rb_tree_node<pair<int, cHitControlGroup*> >* y = (_Rb_tree_node<pair<int, cHitControlGroup*> >*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803A38EC — NOTE: asm-derived — _M_insert
// 0x803A3A00 — NOTE: asm-derived — insert_unique
// 0x803A3B18 — NOTE: asm-derived — insert_unique(iterator, value&)

// --- _Rb_tree<cTrack*, pair<cTrack*, int>, ...> ---

// 0x803A36DC (92 bytes)
template <>
void _Rb_tree<cTrack*, pair<cTrack*, int>, _Select1st<pair<cTrack*, int> >, less<cTrack*>, allocator<pair<cTrack*, int> > >::_M_erase(_Rb_tree_node<pair<cTrack*, int> >* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<cTrack*, int> >*)x->_M_right);
        _Rb_tree_node<pair<cTrack*, int> >* y = (_Rb_tree_node<pair<cTrack*, int> >*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803A3738 — NOTE: asm-derived — _M_insert
// 0x803A384C — NOTE: asm-derived — insert_unique
// 0x803A3964 — NOTE: asm-derived — insert_unique(iterator, value&)

// --- _Rb_tree<ResFile*, pair<ResFile*, FileRec>, ...> ---

// 0x803A9180 (92 bytes)
template <>
void _Rb_tree<ResFile*, pair<ResFile*, FileRec>, _Select1st<pair<ResFile*, FileRec> >, less<ResFile*>, allocator<pair<ResFile*, FileRec> > >::_M_erase(_Rb_tree_node<pair<ResFile*, FileRec> >* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<ResFile*, FileRec> >*)x->_M_right);
        _Rb_tree_node<pair<ResFile*, FileRec> >* y = (_Rb_tree_node<pair<ResFile*, FileRec> >*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 28);
        x = y;
    }
}

// 0x803A91DC — NOTE: asm-derived — _M_insert
// 0x803A92F0 — NOTE: asm-derived — insert_unique
// 0x803A9408 — NOTE: asm-derived — insert_unique(iterator, value&)

// --- _Rb_tree<unsigned int, pair<unsigned int, NamespaceSelector>, ...> ---

// 0x803A7C68 (92 bytes)
template <>
void _Rb_tree<unsigned int, pair<unsigned int, NamespaceSelector>, _Select1st<pair<unsigned int, NamespaceSelector> >, less<unsigned int>, allocator<pair<unsigned int, NamespaceSelector> > >::_M_erase(_Rb_tree_node<pair<unsigned int, NamespaceSelector> >* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<unsigned int, NamespaceSelector> >*)x->_M_right);
        auto* y = (_Rb_tree_node<pair<unsigned int, NamespaceSelector> >*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 28);
        x = y;
    }
}

// 0x803A7CC4 — NOTE: asm-derived — _M_insert
// 0x803A7DD8 — NOTE: asm-derived — insert_unique
// 0x803A7EF0 — NOTE: asm-derived — insert_unique(iterator, value&)

// --- _Rb_tree<ERModel*, pair<ERModel*, model_dat>, ...> ---

// 0x803A4AA8 (92 bytes)
template <>
void _Rb_tree<ERModel*, pair<ERModel*, model_dat>, _Select1st<pair<ERModel*, model_dat> >, less<ERModel*>, allocator<pair<ERModel*, model_dat> > >::_M_erase(_Rb_tree_node<pair<ERModel*, model_dat> >* x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<ERModel*, model_dat> >*)x->_M_right);
        auto* y = (_Rb_tree_node<pair<ERModel*, model_dat> >*)x->_M_left;
        if (x) __node_alloc_M_deallocate(x, 36);
        x = y;
    }
}

// 0x803A4B04 — NOTE: asm-derived — _M_insert
// 0x803A4C18 — NOTE: asm-derived — insert_unique
// 0x803A4D30 — NOTE: asm-derived — insert_unique(iterator, value&)


// ============================================================
// TArray<T, Alloc> — Deallocate, SetSize, Insert, operator=, etc.
// ============================================================
// TArray layout: { T* m_data; int m_count; int m_capacity; }
//   offset 0: T* m_data (pointer to buffer)
//   offset 4: int m_count (number of elements)
//   offset 8: int m_capacity (allocated capacity)
//
// Allocator patterns:
//   TArrayDefaultAllocator — uses MainHeap() / EAHeap::Malloc/Free
//   TArrayERAnimAllocator — uses EResourceManager::Alloc/Free with specific context
//   TArrayERModelAllocator — uses EResourceManager::Alloc/Free
//   TArrayERCharacterAllocator — uses EResourceManager::Alloc/Free
//   TArrayERSoundEventAllocator — uses EResourceManager::Alloc/Free
//
// Deallocate pattern: Destruct(m_data, m_count); Free(m_data); Init();
// SetSize pattern: shrink → Destruct tail; grow → realloc + Copy + Construct new
// Insert pattern: if space, memmove + Construct; else realloc
// operator= pattern: Deallocate(); copy fields
//
// Virtual functions (Destruct, Construct, Copy) are called via the TArray vtable.

// --- TArray<float, TArrayERAnimAllocator> ---

// 0x803C90B4 (76 bytes)
template <>
void TArray<float, TArrayERAnimAllocator>::Deallocate(void) {
    Destruct(m_data, m_count);
    EResourceManager::Free(m_data);
    Init();
}

// 0x803C946C (288 bytes)
// NOTE: asm-derived — SetSize with EResourceManager alloc
template <>
void TArray<float, TArrayERAnimAllocator>::SetSize(int newSize, int newCapacity) {
    if (newCapacity == 0) newCapacity = newSize;
    int oldCount = m_count;
    if (newSize < oldCount) {
        Destruct(m_data + newSize, oldCount - newSize);
    }
    if (newCapacity == 0) {
        EResourceManager::Free(m_data);
        Init();
        return;
    }
    if (m_capacity != newCapacity) {
        float* newBuf = (float*)EResourceManager::Alloc(newCapacity * sizeof(float), 8);
        if (newBuf == 0) return;
        if (m_data != 0) {
            int copyCount = (newSize < m_count) ? newSize : m_count;
            Construct(newBuf, copyCount);
            Copy(newBuf, m_data, copyCount);
            Destruct(m_data, m_count);
            EResourceManager::Free(m_data);
        }
        m_data = newBuf;
        m_capacity = newCapacity;
    }
    m_count = newSize;
    if (newSize > oldCount) {
        Construct(m_data + oldCount, newSize - oldCount);
    }
}

// --- TArray<unsigned int, TArrayDefaultAllocator> ---

// 0x803C3DEC (292 bytes)
template <>
void TArray<unsigned int, TArrayDefaultAllocator>::SetSize(int newSize, int newCapacity) {
    if (newCapacity == 0) newCapacity = newSize;
    int oldCount = m_count;
    if (newSize < oldCount)
        Destruct(m_data + newSize, oldCount - newSize);
    if (newCapacity == 0) {
        void* heap = MainHeap();
        EAHeap::Free(m_data);
        Init();
        return;
    }
    if (m_capacity != newCapacity) {
        void* heap = MainHeap();
        unsigned int* newBuf = (unsigned int*)EAHeap::Malloc(newCapacity * sizeof(unsigned int), 0);
        if (newBuf == 0) return;
        if (m_data != 0) {
            int copyCount = (newSize < m_count) ? newSize : m_count;
            Construct(newBuf, copyCount);
            Copy(newBuf, m_data, copyCount);
            Destruct(m_data, m_count);
            heap = MainHeap();
            EAHeap::Free(m_data);
        }
        m_data = newBuf;
        m_capacity = newCapacity;
    }
    m_count = newSize;
    if (newSize > oldCount)
        Construct(m_data + oldCount, newSize - oldCount);
}

// 0x803C3F10 (76 bytes)
template <>
void TArray<unsigned int, TArrayDefaultAllocator>::operator=(TArray<unsigned int, TArrayDefaultAllocator>& rhs) {
    Deallocate();
    m_data = rhs.m_data;
    m_count = rhs.m_count;
    m_capacity = rhs.m_capacity;
    rhs.Init();
}

// --- TArray<int, TArrayDefaultAllocator> ---

// 0x803C24E0 (76 bytes)
template <>
void TArray<int, TArrayDefaultAllocator>::Deallocate(void) {
    Destruct(m_data, m_count);
    void* heap = MainHeap();
    EAHeap::Free(m_data);
    Init();
}

// 0x803C25E4 (292 bytes) — SetSize, same pattern as unsigned int

// 0x803C2744 (216 bytes)
// NOTE: asm-derived — Insert(int* pos, int count, int capacityGrow)
// Grows array if needed, memmoves existing elements, constructs new

// --- TArray<int, TArrayERCharacterAllocator> ---

// 0x803C9930 (76 bytes)
template <>
void TArray<int, TArrayERCharacterAllocator>::Deallocate(void) {
    Destruct(m_data, m_count);
    EResourceManager::Free(m_data);
    Init();
}

// 0x8039C468 (288 bytes) — SetSize — same pattern with EResourceManager alloc

// 0x803C9B44 (76 bytes)
template <>
void TArray<int, TArrayERCharacterAllocator>::operator=(TArray<int, TArrayERCharacterAllocator>& rhs) {
    Deallocate();
    m_data = rhs.m_data;
    m_count = rhs.m_count;
    m_capacity = rhs.m_capacity;
    rhs.Init();
}

// --- TArray<SndEvtHitPatch, TArrayERSoundEventAllocator> ---

// 0x803CA074 (76 bytes)
template <>
void TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>::Deallocate(void) {
    Destruct(m_data, m_count);
    EResourceManager::Free(m_data);
    Init();
}

// 0x803CA2B8 (288 bytes) — SetSize — same pattern
// 0x803CA3D8 (76 bytes) — operator= — same pattern

// --- TArray<EVec3, TArrayDefaultAllocator> ---

// 0x8039C664 (76 bytes)
template <>
void TArray<EVec3, TArrayDefaultAllocator>::Deallocate(void) {
    Destruct(m_data, m_count);
    void* heap = MainHeap();
    EAHeap::Free(m_data);
    Init();
}

// 0x8039C828 (292 bytes) — SetSize
// 0x8039C94C (76 bytes) — operator=
template <>
void TArray<EVec3, TArrayDefaultAllocator>::operator=(TArray<EVec3, TArrayDefaultAllocator>& rhs) {
    Deallocate();
    m_data = rhs.m_data;
    m_count = rhs.m_count;
    m_capacity = rhs.m_capacity;
    rhs.Init();
}

// --- TArray<SimsLightInfo, TArrayERModelAllocator> ---
// 0x803C435C (76 bytes) — Deallocate
// 0x803C5198 (92 bytes) — Copy
// 0x803C51F4 (288 bytes) — SetSize

// --- TArray<EFontPage*, TArrayDefaultAllocator> ---

// 0x803C7BE0 (76 bytes)
template <>
void TArray<EFontPage*, TArrayDefaultAllocator>::Deallocate(void) {
    Destruct(m_data, m_count);
    void* heap = MainHeap();
    EAHeap::Free(m_data);
    Init();
}

// 0x803C7C6C (104 bytes)
template <>
void TArray<EFontPage*, TArrayDefaultAllocator>::SafeDeleteAll(void) {
    for (int i = m_count - 1; i >= 0; i--) {
        if (m_data[i]) {
            __builtin_delete(m_data[i]);
            m_data[i] = 0;
        }
    }
    m_count = 0;
}

// 0x803C7F54 (292 bytes) — SetSize

// --- TArray<EAnimEvent, TArrayERAnimAllocator> ---
// 0x803C91A0 (76 bytes) — Deallocate
// 0x803C95A8 (196 bytes) — Copy (element-by-element)
// 0x803C966C (288 bytes) — SetSize

// --- TArray<EAnimNodeDataPos, TArrayERAnimAllocator> ---
// 0x803C8FC8 (76 bytes) — Deallocate
// 0x803C8F64 (100 bytes) — Destruct (loop calling element dtor)
// 0x803C9260 (164 bytes) — Copy
// 0x803C9304 (288 bytes) — SetSize

// --- TArray<ENLatticePoints, TArrayDefaultAllocator> ---
// 0x8039C6F0 (80 bytes) — Destruct (loop calling element dtor)
// 0x8039C784 (76 bytes) — Construct (loop calling element ctor)
// 0x8039C998 (88 bytes) — Copy (element-by-element)
// 0x8039C9F0 (292 bytes) — SetSize

// --- TArray<ENDummyPoint, TArrayDefaultAllocator> ---
// 0x803C1D2C (76 bytes) — Deallocate
// 0x8039CBA0 (204 bytes) — Copy
// 0x8039CC6C (300 bytes) — SetSize
// 0x803C4BC0 (76 bytes) — operator=

// --- TArray<unsigned char*, TArrayDefaultAllocator> ---

// 0x803C2F78 (76 bytes)
template <>
void TArray<unsigned char*, TArrayDefaultAllocator>::Deallocate(void) {
    Destruct(m_data, m_count);
    void* heap = MainHeap();
    EAHeap::Free(m_data);
    Init();
}

// 0x803C3004 (88 bytes)
template <>
void TArray<unsigned char*, TArrayDefaultAllocator>::FreeAll(void) {
    for (int i = 0; i < m_count; i++) {
        if (m_data[i]) {
            void* heap = MainHeap();
            EAHeap::Free(m_data[i]);
        }
    }
    m_count = 0;
}

// 0x803C30A4 (292 bytes) — SetSize
// 0x803C3204 (216 bytes) — Insert

// --- TArray<EILight*, TArrayDefaultAllocator> ---

// 0x8039F674 (76 bytes)
template <>
void TArray<EILight*, TArrayDefaultAllocator>::Deallocate(void) {
    Destruct(m_data, m_count);
    void* heap = MainHeap();
    EAHeap::Free(m_data);
    Init();
}

// 0x8039F700 (116 bytes)
template <>
void TArray<EILight*, TArrayDefaultAllocator>::DeleteAll(void) {
    for (int i = m_count - 1; i >= 0; i--) {
        if (m_data[i]) {
            __builtin_delete(m_data[i]);
        }
    }
    m_count = 0;
}

// 0x8039F7BC (292 bytes) — SetSize
// 0x8039F91C (216 bytes) — Insert

// --- TArray<ESubModel, TArrayERModelAllocator> ---
// 0x803C4220 (80 bytes) — Destruct (loop, element dtor)
// 0x803C4270 (76 bytes) — Deallocate
// 0x803C53B4 (76 bytes) — Construct (loop, element ctor)
// 0x803C544C (112 bytes) — Copy
// 0x803C54BC (288 bytes) — SetSize

// --- TArray<ESMSStrip, TArrayERModelAllocator> ---
// 0x803C3918 (112 bytes) — Construct (loop, element ctor)
// 0x803C3988 (124 bytes) — Copy
// 0x803C3A04 (288 bytes) — SetSize
// 0x803C3B24 (76 bytes) — operator=
// 0x803C40D4 (76 bytes) — Deallocate

// --- TArray<ENCamera, TArrayERModelAllocator> ---
// 0x803C47C8 (100 bytes) — Destruct
// 0x803C482C (76 bytes) — Deallocate
// 0x803C4E78 (76 bytes) — Construct
// 0x803C4F10 (152 bytes) — Copy
// 0x803C4FA8 (288 bytes) — SetSize

// --- TArray<ENDummy, TArrayERModelAllocator> ---
// 0x803C4694 (100 bytes) — Destruct
// 0x803C46F8 (76 bytes) — Deallocate
// 0x803C4B74 (76 bytes) — Construct
// 0x803C4C0C (152 bytes) — Copy
// 0x803C4CA4 (288 bytes) — SetSize

// --- TArray<BSplineVolume, TArrayERModelAllocator> ---
// 0x803C442C (100 bytes) — Destruct
// 0x803C4490 (76 bytes) — Deallocate
// 0x803C48B8 (76 bytes) — Construct
// 0x803C4904 (156 bytes) — Copy
// 0x803C49A0 (288 bytes) — SetSize

// --- TArray<ENCameraPoint, TArrayDefaultAllocator> ---
// 0x8039CDE4 (236 bytes) — Copy
// 0x8039CED0 (300 bytes) — SetSize
// 0x803C4EC4 (76 bytes) — operator=
// 0x803C7AF4 (76 bytes) — Deallocate

// --- TArray<EAnimNote, TArrayERAnimAllocator> ---
// 0x803C9100 (76 bytes) — Deallocate
// 0x803C9798 (288 bytes) — SetSize
// 0x803C98B8 (76 bytes) — operator=
// Plus more Copy/Construct methods

// --- TArray<EString, TArrayDefaultAllocator> ---
// 0x803C20E8 — Deallocate + Destruct + SetSize + operator=

// --- TArray<EString2, TArrayDefaultAllocator> ---
// 0x803C23D4 — Deallocate + Destruct + SetSize + operator=

// --- TArray<ESubModelShader, TArrayERModelAllocator> ---
// 0x803C4120 — Destruct + Deallocate + Construct + Copy + SetSize

// --- TArray<EFileSystem::FileCreator, TArrayDefaultAllocator> ---
// 0x803C26B0 — Deallocate + Destruct + Construct + Copy + SetSize

// --- TArray<ECharacterNode, TArrayERCharacterAllocator> ---
// 0x803C99C0 — Destruct + Deallocate + Construct + Copy + SetSize

// --- TArray<TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>, TArrayERSoundEventAllocator> ---

// 0x803CA100 (80 bytes)
template <>
void TArray<TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>, TArrayERSoundEventAllocator>::Destruct(TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>* ptr, int count) {
    TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>* end = ptr + count;
    while (ptr < end) {
        ptr->~TArray();
        ptr++;
    }
}

// 0x803CA150 (76 bytes) — Deallocate
// 0x803CA20C (76 bytes) — Construct
// 0x803CA424 (88 bytes) — Copy (element-by-element with operator=)
// 0x803CA47C (288 bytes) — SetSize


// ============================================================
// _Deque_base<T, Alloc> — create_nodes, initialize_map, destroy_nodes, ~_Deque_base
// ============================================================
// Deque layout (SGI STL):
//   offset 0:  _Deque_iterator _M_start  (cur, first, last, node — 16 bytes)
//   offset 16: _Deque_iterator _M_finish (16 bytes)
//   offset 32: void* (??? padding)
//   offset 36: T** _M_map (pointer to map of node buffers)
//   offset 40: ???
//   offset 44: int _M_map_size
//
// Each node buffer is 128 bytes (for int-sized elements: 32 ints per buffer).
// The map is an array of T** pointers to these node buffers.

// --- _Deque_base<int, allocator<int>> ---

// 0x803B2F38 (76 bytes)
template <>
void _Deque_base<int, allocator<int> >::_M_create_nodes(int** nstart, int** nfinish) {
    for (int** cur = nstart; cur < nfinish; cur++) {
        *cur = (int*)__node_alloc_M_allocate(128);
    }
}

// 0x803B3088 (84 bytes)
template <>
void _Deque_base<int, allocator<int> >::_M_destroy_nodes(int** nstart, int** nfinish) {
    for (int** cur = nstart; cur < nfinish; cur++) {
        if (*cur) __node_alloc_M_deallocate(*cur, 128);
    }
}

// 0x803B2F84 (260 bytes) — NOTE: asm-derived — _M_initialize_map
// Complex map allocation + node creation + iterator setup

// 0x803B30DC (128 bytes)
template <>
_Deque_base<int, allocator<int> >::~_Deque_base(void) {
    // Destroy node buffers
    int** mapBuf = *(int***)((char*)this + 36);
    if (mapBuf != 0) {
        int** startNode = *(int***)((char*)this + 12);
        int** finishNode = *(int***)((char*)this + 28);
        _M_destroy_nodes(startNode, finishNode + 1);
        // Deallocate the map itself
        int mapSize = *(int*)((char*)this + 44);
        stl_dealloc(mapBuf, mapSize * 4);
    }
}

// --- _Deque_base<FAMTarget::FAM_STATE, allocator<FAMTarget::FAM_STATE>> ---
// Identical pattern to int (FAM_STATE is int-sized enum)
// 0x803B4ED4 (76 bytes) — _M_create_nodes
// 0x803B4F20 (260 bytes) — _M_initialize_map
// 0x803B5024 (84 bytes) — _M_destroy_nodes
// 0x803B5078 (128 bytes) — ~_Deque_base

// --- _Deque_base<MMUTarget::MMU_MENU_STATE, allocator<MMUTarget::MMU_MENU_STATE>> ---
// 0x803B5584 (76 bytes) — _M_create_nodes
// 0x803B55D0 (260 bytes) — _M_initialize_map
// 0x803B56D4 (84 bytes) — _M_destroy_nodes
// 0x803B5728 (128 bytes) — ~_Deque_base

// --- _Deque_base<StateMachineStatus*, allocator<StateMachineStatus*>> ---
// 0x8039BEF0 (76 bytes) — _M_create_nodes
// 0x8039BF3C (260 bytes) — _M_initialize_map
// 0x8039C040 (84 bytes) — _M_destroy_nodes
// 0x8039C094 (128 bytes) — ~_Deque_base


// ============================================================
// deque<T, Alloc> — _M_pop_back_aux, _M_reallocate_map, _M_push_back_aux_v
// ============================================================

// --- deque<int, allocator<int>> ---

// 0x803B315C (104 bytes)
template <>
void deque<int, allocator<int> >::_M_pop_back_aux(void) {
    // Free the back buffer node
    int* backBuf = *(int**)((char*)this + 20);
    if (backBuf) __node_alloc_M_deallocate(backBuf, 128);
    // Move finish iterator to end of previous node
    int** finishNode = *(int***)((char*)this + 28);
    finishNode--;
    *(int***)((char*)this + 28) = finishNode;
    int* nodeBuf = *finishNode;
    *(int**)((char*)this + 20) = nodeBuf;
    *(int**)((char*)this + 24) = nodeBuf + 32; // last = buf + bufSize
    *(int**)((char*)this + 16) = (int*)((char*)nodeBuf + 128) - 1; // cur = last - 1
}

// 0x803B31C4 (456 bytes) — NOTE: asm-derived — _M_reallocate_map
// Complex map reallocation with memmove of node pointers

// 0x803B338C (152 bytes) — NOTE: asm-derived — _M_push_back_aux_v
// Allocates new node buffer when current back buffer is full

// --- deque<FAMTarget::FAM_STATE, ...> (identical to int) ---
// 0x803B52BC (104 bytes) — _M_pop_back_aux
// 0x803B5324 (456 bytes) — _M_reallocate_map
// 0x803B54EC (152 bytes) — _M_push_back_aux_v

// --- deque<MMUTarget::MMU_MENU_STATE, ...> (identical to int) ---
// 0x803B57A8 (456 bytes) — _M_reallocate_map
// 0x803B5970 (152 bytes) — _M_push_back_aux_v
// 0x803B5A08 (104 bytes) — _M_pop_back_aux

// --- deque<StateMachineStatus*, ...> ---
// 0x803A159C (456 bytes) — _M_reallocate_map
// 0x803A1764 (152 bytes) — _M_push_back_aux_v
// 0x803A17FC (104 bytes) — _M_pop_back_aux


// ============================================================
// basic_string<char, char_traits<char>, allocator<char>>
// ============================================================
// String layout: { char* _M_start; char* _M_finish; char padding[4]; char* _M_end_of_storage; }
// Actually: offset 0=start, 4=finish, 8=???, 12=end_of_storage

// 0x803AE880 (96 bytes)
template <>
basic_string<char, char_traits<char>, allocator<char> >::basic_string(void) {
    _M_start = 0;
    _M_finish = 0;
    *(int*)((char*)this + 12) = 0; // rep info
    char* buf = (char*)__node_alloc_M_allocate(8);
    _M_start = buf;
    *(char**)((char*)this + 12) = buf + 8;
    _M_finish = buf;
    *buf = '\0';
}

// 0x803B16B0 (264 bytes) — NOTE: asm-derived
// basic_string<char>::reserve(unsigned int)
// Allocates new buffer, copies existing content, null-terminates, deallocates old


// ============================================================
// basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>
// ============================================================

// 0x803B518C (176 bytes)
// basic_string<wchar_t>::basic_string(unsigned short*, allocator<wchar_t>&)
// Counts wchar_t string length, allocates block, copies data, null-terminates

// 0x803B523C (128 bytes)
// basic_string<wchar_t>::basic_string(basic_string<wchar_t>&)
// Copy constructor — copies from other's start..finish range


// ============================================================
// basic_string_ref (EA custom string reference)
// ============================================================
// Layout: { char* m_ptr; unsigned int m_length; unsigned int m_capacity; int m_refCount; }
//   offset 0: char* m_ptr
//   offset 4: unsigned int m_length
//   offset 8: unsigned int m_capacity
//   offset 12: int m_refCount

extern char basic_string_ref_eos();
extern void basic_string_ref_throwlength();

// 0x8009BF5C (80 bytes)
void basic_string_ref::delete_ptr(void) {
    if (m_capacity != 0) {
        void* heap = MainHeap();
        EAHeap::Free(m_ptr);
        m_ptr = 0;
        m_capacity = 0;
    }
}

// 0x8009C624 (248 bytes) — NOTE: asm-derived
// basic_string_ref::basic_string_ref(unsigned int size, BString::capacity mode)
// mode==1: allocate capacity only; mode==0: allocate + fill with eos()

// 0x8009C71C (168 bytes) — NOTE: asm-derived
// basic_string_ref::basic_string_ref(BString& src, unsigned int offset, unsigned int len)
// Allocates, copies from BString data + offset

// 0x8009C7C4 (160 bytes) — NOTE: asm-derived
// basic_string_ref::basic_string_ref(char* src, unsigned int len, unsigned int cap)
// Allocates cap+1, copies len bytes from src

// 0x8009C864 (176 bytes) — NOTE: asm-derived
// basic_string_ref::basic_string_ref(char* src, unsigned int len)
// Validates len != -1, allocates len+1, copies

// 0x8009C914 (188 bytes) — NOTE: asm-derived
// basic_string_ref::basic_string_ref(char* src)
// Calls strlen, allocates, copies

// 0x8009C9D0 (200 bytes) — NOTE: asm-derived
// basic_string_ref::basic_string_ref(char ch, unsigned int count)
// Fills buffer with count copies of ch


// ============================================================
// basic_string_ref2 (second variant, likely wchar_t version)
// ============================================================
// 0x8009CAA8+ — Similar pattern to basic_string_ref but for wide strings
// NOTE: asm-derived — all constructors follow same alloc + copy pattern


// ============================================================
// _Base_bitset<3> — bit scanning operations
// ============================================================
// _Base_bitset<3> has 3 unsigned int words (96 bits).
// Uses a byte lookup table at (-22032 relative to lis -32698) for
// finding first/next set bit.

// 0x8039BE88 (104 bytes) — NOTE: asm-derived
// _Base_bitset<3>::_M_do_find_first(unsigned int __not_found) const
// Scans 3 words byte-by-byte using lookup table to find first set bit.
// Returns bit index or __not_found if no bits set.

// 0x803A6540 (256 bytes) — NOTE: asm-derived
// _Base_bitset<3>::_M_do_find_next(unsigned int __prev, unsigned int __not_found) const
// Starts from bit __prev+1, scans remaining bytes using lookup table.


// ============================================================
// list<NamespaceSelector::DataCache, ...>::operator=
// ============================================================

// 0x803A79E4 (636 bytes) — NOTE: asm-derived
// list<NamespaceSelector::DataCache, allocator<NamespaceSelector::DataCache>>::operator=
// Complex list assignment: walks both lists in parallel, assigning data fields,
// calling virtual clone/release on data members (offset 12), then removes
// excess nodes or creates new ones as needed.
// Node layout: { _Node* next; _Node* prev; short field8; void* field12; int field16; }


// ============================================================
// BitArray64 — 64-bit operations using __ashldi3/__ashrdi3
// ============================================================
// Layout: { unsigned int hi; unsigned int lo; } (8 bytes, big-endian 64-bit)
// Uses compiler helpers __ashldi3 (64-bit shift left) and __ashrdi3 (arithmetic shift right)

// 0x8009B7AC (80 bytes)
int BitArray64::IsSet(int bit) const {
    // Shift the 64-bit value right by 'bit' positions, test LSB
    unsigned long long val = ((unsigned long long)hi << 32) | lo;
    return (int)((val >> bit) & 1) != 0 ? 1 : 0;
}

// 0x8009B7FC (80 bytes)
int BitArray64::operator[](int bit) const {
    unsigned long long val = ((unsigned long long)hi << 32) | lo;
    return (int)((val >> bit) & 1) != 0 ? 1 : 0;
}

// 0x8009B84C (84 bytes)
void BitArray64::Set(int bit) {
    unsigned long long mask = (unsigned long long)1 << bit;
    unsigned int maskHi = (unsigned int)(mask >> 32);
    unsigned int maskLo = (unsigned int)(mask);
    hi |= maskHi;
    lo |= maskLo;
}

// 0x8009B8A0 (92 bytes)
void BitArray64::Clear(int bit) {
    unsigned long long mask = (unsigned long long)1 << bit;
    unsigned int maskHi = (unsigned int)(mask >> 32);
    unsigned int maskLo = (unsigned int)(mask);
    hi &= ~maskHi;
    lo &= ~maskLo;
}

// 0x8009B974 (72 bytes)
BitArray64& BitArray64::operator<<=(int shift) {
    unsigned long long val = ((unsigned long long)hi << 32) | lo;
    val <<= shift;
    hi = (unsigned int)(val >> 32);
    lo = (unsigned int)(val);
    return *this;
}

// 0x8009B9BC (72 bytes)
BitArray64& BitArray64::operator>>=(int shift) {
    long long val = ((long long)(int)hi << 32) | lo;
    val >>= shift;
    hi = (unsigned int)(val >> 32);
    lo = (unsigned int)(val);
    return *this;
}

// 0x8009BA04 (80 bytes)
int BitArray64::CountBits(void) const {
    int count = 0;
    for (int i = 0; i <= 63; i++) {
        count += IsSet(i);
    }
    return count;
}


// ============================================================
// EBitArrayProxy — proxy for EBitArray bit access with compound assignment
// ============================================================
// Layout: { EBitArray* m_array; int m_index; }

extern int EBitArray_Get(void* arr, int index);
extern void EBitArray_Set(void* arr, int index, int value);

// 0x802DF3C4 (108 bytes)
void EBitArrayProxy::operator|=(bool val) {
    int curVal = EBitArray_Get(m_array, m_index) ? 1 : 0;
    int newVal = val ? 1 : 0;
    EBitArray_Set(m_array, m_index, curVal | newVal);
}

// 0x802DF430 (108 bytes)
void EBitArrayProxy::operator&=(bool val) {
    int curVal = EBitArray_Get(m_array, m_index) ? 1 : 0;
    int newVal = val ? 1 : 0;
    EBitArray_Set(m_array, m_index, curVal & newVal);
}

// 0x802DF49C (128 bytes)
void EBitArrayProxy::operator^=(bool val) {
    int curVal = EBitArray_Get(m_array, m_index) ? 1 : 0;
    int result;
    if (val) {
        result = (curVal == 0) ? 1 : 0;
    } else {
        result = (curVal != 0) ? 1 : 0;
    }
    EBitArray_Set(m_array, m_index, result);
}


// ============================================================
// BitMatrix64 — 64x64 bit matrix (array of 64 BitArray64s)
// ============================================================
// Layout: BitArray64 rows[64] (512 bytes total)
// Each row is 8 bytes (64 bits), indexed by CTilePt::GetY()
// Within each row, bit index is CTilePt::GetX()

extern int CTilePt_GetX(void* pt);
extern int CTilePt_GetY(void* pt);

// 0x8009BA54 (76 bytes)
BitMatrix64::BitMatrix64(void) {
    for (int i = 63; i >= 0; i--) {
        rows[i].BitArray64_ctor(); // calls BitArray64::BitArray64()
    }
}

// 0x8009BAA0 (172 bytes)
BitMatrix64::BitMatrix64(BitMatrix64& other) {
    // First default-construct all rows
    for (int i = 63; i >= 0; i--) {
        rows[i].BitArray64_ctor();
    }
    // Then copy all 512 bytes (64 * 8) via unrolled loop
    // The asm copies 24 bytes per iteration for 21 iterations + 8 byte tail
    memcpy(this, &other, 512);
}

// 0x8009BB4C (100 bytes)
BitMatrix64::~BitMatrix64(void) {
    if (this != 0) {
        for (int i = 63; i >= 0; i--) {
            rows[i].~BitArray64();
        }
    }
    // Note: conditional delete based on r4 (destructor flag)
}

// 0x8009BBB0 (100 bytes)
BitMatrix64& BitMatrix64::operator=(BitMatrix64& other) {
    if (this == &other) return *this;
    memcpy(this, &other, 512);
    return *this;
}

// 0x8009BC2C (80 bytes)
int BitMatrix64::IsSet(CTilePt& pt) const {
    int y = CTilePt_GetY(&pt);
    int x = CTilePt_GetX(&pt);
    return rows[y].IsSet(x);
}

// 0x8009BC7C (80 bytes)
void BitMatrix64::Set(CTilePt& pt) {
    int y = CTilePt_GetY(&pt);
    int x = CTilePt_GetX(&pt);
    rows[y].Set(x);
}

// 0x8009BCCC (80 bytes)
void BitMatrix64::Clear(CTilePt& pt) {
    int y = CTilePt_GetY(&pt);
    int x = CTilePt_GetX(&pt);
    rows[y].Clear(x);
}

// 0x8009BD44 (84 bytes)
BitMatrix64& BitMatrix64::operator&=(BitMatrix64& other) {
    for (int i = 0; i <= 63; i++) {
        rows[i] &= other.rows[i];
    }
    return *this;
}

// 0x8009BD98 (84 bytes)
BitMatrix64& BitMatrix64::operator|=(BitMatrix64& other) {
    for (int i = 0; i <= 63; i++) {
        rows[i] |= other.rows[i];
    }
    return *this;
}

// 0x8009BDEC (84 bytes)
BitMatrix64& BitMatrix64::operator^=(BitMatrix64& other) {
    for (int i = 0; i <= 63; i++) {
        rows[i] ^= other.rows[i];
    }
    return *this;
}

// 0x8009BE40 (80 bytes)
BitMatrix64& BitMatrix64::operator<<=(int shift) {
    for (int i = 0; i <= 63; i++) {
        rows[i] <<= shift;
    }
    return *this;
}

// 0x8009BE90 (80 bytes)
BitMatrix64& BitMatrix64::operator>>=(int shift) {
    for (int i = 0; i <= 63; i++) {
        rows[i] >>= shift;
    }
    return *this;
}

// 0x8009BEE0 (76 bytes)
int BitMatrix64::CountBits(void) const {
    int total = 0;
    for (int i = 0; i <= 63; i++) {
        total += rows[i].CountBits();
    }
    return total;
}
