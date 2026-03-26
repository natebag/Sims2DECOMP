// stl_containers.cpp - STL container template instantiation stubs
// Covers: List_base (10), Rb_tree (15), TArray (28), stack (4), String_base (1), byte_key_map (1), Base_bitset (1)
//
// Simple patterns (List_base::clear, simple Rb_tree::_M_erase) are converted to portable C++.
// Complex patterns (Rb_tree insert/copy/operator=, TArray, stack, String_base, byte_key_map,
// Base_bitset) remain as inline PPC asm because their control flow is too intricate to
// convert without risking byte-match regressions.

#include "types.h"
#include "templates/stl_types.h"
#include "templates/tarray_types.h"

// External function declarations
extern void* __node_alloc_M_deallocate(void* ptr, unsigned int size);
extern void* __node_alloc_M_allocate(unsigned int size);

// These are provided by the runtime / other TUs
extern "C" void __builtin_delete(void*);
extern "C" void* __builtin_new(unsigned int);


// ============================================================
// _List_base<T, Alloc>::clear() -- 10 instantiations
// ============================================================
// Pattern: Walk the linked list from sentinel->next, deallocate each node
// via __node_alloc<false,0>::_M_deallocate(node, sizeof_node),
// then reset sentinel->next = sentinel->prev = sentinel.
//
// List node layout:
//   struct _List_node { _List_node* next; _List_node* prev; T data; };
//   sizeof_node = 8 + sizeof(T)
//
// _List_base layout:
//   offset 0: ??? (this pointer occupies this)
//   offset 4: _List_node* sentinel (points to the sentinel node)

// Helper for the simple (no element destructor) list clear pattern.
// All 9 "simple" list clears have identical asm, differing only in the
// node size passed to _M_deallocate.
//
// The NamespaceSelector::DataCache variant is DIFFERENT -- it calls a
// virtual destructor on each element before deallocating -- so it stays as asm.

// --- Helper: generic list clear (no element dtor) ---
// Sentinel is at this+4. Node layout: [next, prev, data...], sizeof = node_size.
// This matches the 108-byte asm pattern exactly.

// ---- Simple list clears (108 bytes each, node_size = 8 + sizeof(T)) ----

// 0x803B4E68 (108 bytes)
// _List_base<ACTTarget::iqRecord *, allocator<ACTTarget::iqRecord *> >::clear()
// Node: next(4) + prev(4) + ptr(4) = 12
template <>
void _List_base<ACTTarget::iqRecord *, allocator<ACTTarget::iqRecord *> >::clear(void) {
    struct _Node { _Node* next; _Node* prev; ACTTarget::iqRecord* data; };
    _Node* sentinel = *(_Node**)((char*)this + 4);
    _Node* cur = sentinel->next;
    while (cur != sentinel) {
        _Node* next = cur->next;
        if (cur) __node_alloc_M_deallocate(cur, 12);
        cur = next;
    }
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
}

// 0x803A8804 (108 bytes)
// _List_base<PassiveInfluenceObject *, allocator<PassiveInfluenceObject *> >::clear()
// Node: 8 + 4 = 12
template <>
void _List_base<PassiveInfluenceObject *, allocator<PassiveInfluenceObject *> >::clear(void) {
    struct _Node { _Node* next; _Node* prev; PassiveInfluenceObject* data; };
    _Node* sentinel = *(_Node**)((char*)this + 4);
    _Node* cur = sentinel->next;
    while (cur != sentinel) {
        _Node* next = cur->next;
        if (cur) __node_alloc_M_deallocate(cur, 12);
        cur = next;
    }
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
}

// 0x803A87E0 -> actually 0x803A8798 (108 bytes)
// _List_base<PassiveInfluencePerson *, allocator<PassiveInfluencePerson *> >::clear()
// Node: 8 + 4 = 12
template <>
void _List_base<PassiveInfluencePerson *, allocator<PassiveInfluencePerson *> >::clear(void) {
    struct _Node { _Node* next; _Node* prev; PassiveInfluencePerson* data; };
    _Node* sentinel = *(_Node**)((char*)this + 4);
    _Node* cur = sentinel->next;
    while (cur != sentinel) {
        _Node* next = cur->next;
        if (cur) __node_alloc_M_deallocate(cur, 12);
        cur = next;
    }
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
}

// 0x803A8870 (108 bytes)
// _List_base<PassiveInfluenceTarget *, allocator<PassiveInfluenceTarget *> >::clear()
// Node: 8 + 4 = 12
template <>
void _List_base<PassiveInfluenceTarget *, allocator<PassiveInfluenceTarget *> >::clear(void) {
    struct _Node { _Node* next; _Node* prev; PassiveInfluenceTarget* data; };
    _Node* sentinel = *(_Node**)((char*)this + 4);
    _Node* cur = sentinel->next;
    while (cur != sentinel) {
        _Node* next = cur->next;
        if (cur) __node_alloc_M_deallocate(cur, 12);
        cur = next;
    }
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
}

// 0x803AB048 (108 bytes)
// _List_base<ScoredInteraction, allocator<ScoredInteraction> >::clear()
// Node: 8 + 36 = 44 (li 4,44)
template <>
void _List_base<ScoredInteraction, allocator<ScoredInteraction> >::clear(void) {
    struct _Node { _Node* next; _Node* prev; char data[36]; };
    _Node* sentinel = *(_Node**)((char*)this + 4);
    _Node* cur = sentinel->next;
    while (cur != sentinel) {
        _Node* next = cur->next;
        if (cur) __node_alloc_M_deallocate(cur, 44);
        cur = next;
    }
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
}

// 0x803A93EC (108 bytes)
// _List_base<cTrack *, allocator<cTrack *> >::clear()
// Node: 8 + 4 = 12
template <>
void _List_base<cTrack *, allocator<cTrack *> >::clear(void) {
    struct _Node { _Node* next; _Node* prev; cTrack* data; };
    _Node* sentinel = *(_Node**)((char*)this + 4);
    _Node* cur = sentinel->next;
    while (cur != sentinel) {
        _Node* next = cur->next;
        if (cur) __node_alloc_M_deallocate(cur, 12);
        cur = next;
    }
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
}

// 0x8039D55C (108 bytes)
// _List_base<pair<cXObject *, int>, allocator<pair<cXObject *, int> > >::clear()
// Node: 8 + 8 = 16 (li 4,16)
template <>
void _List_base<pair<cXObject *, int>, allocator<pair<cXObject *, int> > >::clear(void) {
    struct _Node { _Node* next; _Node* prev; pair<cXObject*, int> data; };
    _Node* sentinel = *(_Node**)((char*)this + 4);
    _Node* cur = sentinel->next;
    while (cur != sentinel) {
        _Node* next = cur->next;
        if (cur) __node_alloc_M_deallocate(cur, 16);
        cur = next;
    }
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
}

// 0x803A36A4 (108 bytes)
// _List_base<SoundEventInfo, allocator<SoundEventInfo> >::clear()
// Node: 8 + 12 = 20 (li 4,20)
template <>
void _List_base<SoundEventInfo, allocator<SoundEventInfo> >::clear(void) {
    struct _Node { _Node* next; _Node* prev; char data[12]; };
    _Node* sentinel = *(_Node**)((char*)this + 4);
    _Node* cur = sentinel->next;
    while (cur != sentinel) {
        _Node* next = cur->next;
        if (cur) __node_alloc_M_deallocate(cur, 20);
        cur = next;
    }
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
}

// 0x803A9458 (108 bytes)
// _List_base<unsigned int, allocator<unsigned int> >::clear()
// Node: 8 + 4 = 12
template <>
void _List_base<unsigned int, allocator<unsigned int> >::clear(void) {
    struct _Node { _Node* next; _Node* prev; unsigned int data; };
    _Node* sentinel = *(_Node**)((char*)this + 4);
    _Node* cur = sentinel->next;
    while (cur != sentinel) {
        _Node* next = cur->next;
        if (cur) __node_alloc_M_deallocate(cur, 12);
        cur = next;
    }
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
}

// ---- NamespaceSelector::DataCache list clear (148 bytes, has virtual dtor call) ----
// 0x803A295C (148 bytes)
// _List_base<NamespaceSelector::DataCache, allocator<NamespaceSelector::DataCache> >::clear()
// This variant calls a virtual destructor on each element (offset 12 = data start,
// vtable at data+0, dtor offset at vtable+24, dtor fn at vtable+28).
// Node size: 20 (8 + 12 for DataCache which has a vtable ptr + more).
// TOO COMPLEX for safe portable C++ conversion -- remains as inline asm.
__attribute__((noreturn))
void _List_base<NamespaceSelector::DataCache, allocator<NamespaceSelector::DataCache> >::clear(void) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "mr	29,3\n"
        "lwz	9,4(29)\n"
        "lwz	30,0(9)\n"
        "cmpw	30,9\n"
        "beq	.L_803A29CC\n"
        ".L_803A2980:\n"
        "mr	31,30\n"
        "lwz	11,12(31)\n"
        "lwz	30,0(30)\n"
        "cmpwi	11,0\n"
        "beq	.L_803A29AC\n"
        "lwz	9,0(11)\n"
        "lha	3,24(9)\n"
        "lwz	0,28(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_803A29AC:\n"
        "cmpwi	31,0\n"
        "beq	.L_803A29C0\n"
        "mr	3,31\n"
        "li	4,20\n"
        ".long 0x4bff94a5  /* bl __node_alloc<false, 0>::_M_deallocate(void *, unsigned int) */\n"
        ".L_803A29C0:\n"
        "lwz	0,4(29)\n"
        "cmpw	30,0\n"
        "bne	.L_803A2980\n"
        ".L_803A29CC:\n"
        "lwz	9,4(29)\n"
        "stw	9,0(9)\n"
        "lwz	11,4(29)\n"
        "stw	11,4(11)\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
    __builtin_unreachable();
}


// ============================================================
// _Rb_tree<...>::_M_erase() -- 15 instantiations
// ============================================================
// Pattern: Recursive post-order traversal freeing all nodes.
//   while (x != NULL) { _M_erase(x->right); y = x->left; deallocate(x); x = y; }
//
// _Rb_tree_node layout (SN Systems STL):
//   offset 0: color (int)
//   offset 4: parent (_Rb_tree_node_base*)
//   offset 8: left (_Rb_tree_node_base*)
//   offset 12: right (_Rb_tree_node_base*)
//   offset 16+: data (pair<Key, Value>)
//
// Three sub-patterns:
//   A) Simple: no element destructor (92 bytes each)
//   B) With BString dtor: calls BString::~BString on element before dealloc (104 bytes)
//   C) With other dtor: calls CTilePt::~CTilePt or NamespaceSelector::~NamespaceSelector (104 bytes)
//
// Only _M_erase is converted here. The other Rb_tree methods (_M_insert,
// insert_unique, insert_equal, _M_copy, operator=) are deeply algorithmic
// and remain as inline asm in the original stub files.

// ---- Pattern A: Simple _M_erase (no element destructor, 92 bytes) ----

// 0x803A29F0 (92 bytes)
// _Rb_tree<int, pair<int, int>, _Select1st<...>, less<int>, ...>::_M_erase(...)
template <>
void _Rb_tree<int, pair<int, int>, _Select1st<pair<int, int> >, less<int>, allocator<pair<int, int> > >::_M_erase(_Rb_tree_node<pair<int, int> > * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<int, int> >*)(*(void**)((char*)x + 12)));  // right child
        _Rb_tree_node<pair<int, int> >* y = (_Rb_tree_node<pair<int, int> >*)(*(void**)((char*)x + 8));  // left child
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803B5A70 (92 bytes)
// _Rb_tree<int, pair<int, int>, _Select1st<...>, greater<int>, ...>::_M_erase(...)
template <>
void _Rb_tree<int, pair<int, int>, _Select1st<pair<int, int> >, greater<int>, allocator<pair<int, int> > >::_M_erase(_Rb_tree_node<pair<int, int> > * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<int, int> >*)(*(void**)((char*)x + 12)));
        _Rb_tree_node<pair<int, int> >* y = (_Rb_tree_node<pair<int, int> >*)(*(void**)((char*)x + 8));
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803B0AC0 (92 bytes)
// _Rb_tree<CasListener *, CasListener *, _Identity<...>, less<...>, ...>::_M_erase(...)
// Node size: 20 (16 header + 4 ptr)
template <>
void _Rb_tree<CasListener *, CasListener *, _Identity<CasListener *>, less<CasListener *>, allocator<CasListener *> >::_M_erase(_Rb_tree_node<CasListener *> * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<CasListener *>*)(*(void**)((char*)x + 12)));
        _Rb_tree_node<CasListener *>* y = (_Rb_tree_node<CasListener *>*)(*(void**)((char*)x + 8));
        if (x) __node_alloc_M_deallocate(x, 20);
        x = y;
    }
}

// 0x8039FA5C (92 bytes)
// _Rb_tree<ERModel *, pair<ERModel *, model_dat>, ...>::_M_erase(...)
// Node size: 32
template <>
void _Rb_tree<ERModel *, pair<ERModel *, model_dat>, _Select1st<pair<ERModel *, model_dat> >, less<ERModel *>, allocator<pair<ERModel *, model_dat> > >::_M_erase(_Rb_tree_node<pair<ERModel *, model_dat> > * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<ERModel *, model_dat> >*)(*(void**)((char*)x + 12)));
        _Rb_tree_node<pair<ERModel *, model_dat> >* y = (_Rb_tree_node<pair<ERModel *, model_dat> >*)(*(void**)((char*)x + 8));
        if (x) __node_alloc_M_deallocate(x, 32);
        x = y;
    }
}

// 0x803A2BA0 (92 bytes)
// _Rb_tree<ERSoundEvent *, pair<ERSoundEvent *, int>, ...>::_M_erase(...)
// Node size: 24
template <>
void _Rb_tree<ERSoundEvent *, pair<ERSoundEvent *, int>, _Select1st<pair<ERSoundEvent *, int> >, less<ERSoundEvent *>, allocator<pair<ERSoundEvent *, int> > >::_M_erase(_Rb_tree_node<pair<ERSoundEvent *, int> > * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<ERSoundEvent *, int> >*)(*(void**)((char*)x + 12)));
        _Rb_tree_node<pair<ERSoundEvent *, int> >* y = (_Rb_tree_node<pair<ERSoundEvent *, int> >*)(*(void**)((char*)x + 8));
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803A69B0 (92 bytes)
// _Rb_tree<ResFile *, pair<ResFile *, FileRec>, ...>::_M_erase(...)
// Node size: 28
template <>
void _Rb_tree<ResFile *, pair<ResFile *, FileRec>, _Select1st<pair<ResFile *, FileRec> >, less<ResFile *>, allocator<pair<ResFile *, FileRec> > >::_M_erase(_Rb_tree_node<pair<ResFile *, FileRec> > * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<ResFile *, FileRec> >*)(*(void**)((char*)x + 12)));
        _Rb_tree_node<pair<ResFile *, FileRec> >* y = (_Rb_tree_node<pair<ResFile *, FileRec> >*)(*(void**)((char*)x + 8));
        if (x) __node_alloc_M_deallocate(x, 28);
        x = y;
    }
}

// 0x803A94C4 (92 bytes)
// _Rb_tree<cTrack *, pair<cTrack *, int>, ...>::_M_erase(...)
// Node size: 24
template <>
void _Rb_tree<cTrack *, pair<cTrack *, int>, _Select1st<pair<cTrack *, int> >, less<cTrack *>, allocator<pair<cTrack *, int> > >::_M_erase(_Rb_tree_node<pair<cTrack *, int> > * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<cTrack *, int> >*)(*(void**)((char*)x + 12)));
        _Rb_tree_node<pair<cTrack *, int> >* y = (_Rb_tree_node<pair<cTrack *, int> >*)(*(void**)((char*)x + 8));
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803A9390 (92 bytes)
// _Rb_tree<int, pair<int, cHitControlGroup *>, ...>::_M_erase(...)
// Node size: 24
template <>
void _Rb_tree<int, pair<int, cHitControlGroup *>, _Select1st<pair<int, cHitControlGroup *> >, less<int>, allocator<pair<int, cHitControlGroup *> > >::_M_erase(_Rb_tree_node<pair<int, cHitControlGroup *> > * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<int, cHitControlGroup *> >*)(*(void**)((char*)x + 12)));
        _Rb_tree_node<pair<int, cHitControlGroup *> >* y = (_Rb_tree_node<pair<int, cHitControlGroup *> >*)(*(void**)((char*)x + 8));
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803AB474 (92 bytes)
// _Rb_tree<short, pair<short, bool>, ...>::_M_erase(...)
// Node size: 24
template <>
void _Rb_tree<short, pair<short, bool>, _Select1st<pair<short, bool> >, less<short>, allocator<pair<short, bool> > >::_M_erase(_Rb_tree_node<pair<short, bool> > * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<short, bool> >*)(*(void**)((char*)x + 12)));
        _Rb_tree_node<pair<short, bool> >* y = (_Rb_tree_node<pair<short, bool> >*)(*(void**)((char*)x + 8));
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803AE964 (92 bytes)
// _Rb_tree<pair<unsigned int, ObjectDataID>, pair<..., ISmartDataFactory::tDataProvider>, ...>::_M_erase(...)
// Node size: 32
template <>
void _Rb_tree<pair<unsigned int, ObjectDataID>, pair<pair<unsigned int, ObjectDataID>, ISmartDataFactory::tDataProvider>, _Select1st<pair<pair<unsigned int, ObjectDataID>, ISmartDataFactory::tDataProvider> >, less<pair<unsigned int, ObjectDataID> >, allocator<pair<pair<unsigned int, ObjectDataID>, ISmartDataFactory::tDataProvider> > >::_M_erase(_Rb_tree_node<pair<pair<unsigned int, ObjectDataID>, int> > * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<pair<unsigned int, ObjectDataID>, int> >*)(*(void**)((char*)x + 12)));
        _Rb_tree_node<pair<pair<unsigned int, ObjectDataID>, int> >* y = (_Rb_tree_node<pair<pair<unsigned int, ObjectDataID>, int> >*)(*(void**)((char*)x + 8));
        if (x) __node_alloc_M_deallocate(x, 32);
        x = y;
    }
}

// 0x803A68EC (92 bytes)
// _Rb_tree<unsigned int, pair<unsigned int, iResFile *>, ...>::_M_erase(...)
// Node size: 24
template <>
void _Rb_tree<unsigned int, pair<unsigned int, iResFile *>, _Select1st<pair<unsigned int, iResFile *> >, less<unsigned int>, allocator<pair<unsigned int, iResFile *> > >::_M_erase(_Rb_tree_node<pair<unsigned int, iResFile *> > * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<unsigned int, iResFile *> >*)(*(void**)((char*)x + 12)));
        _Rb_tree_node<pair<unsigned int, iResFile *> >* y = (_Rb_tree_node<pair<unsigned int, iResFile *> >*)(*(void**)((char*)x + 8));
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// 0x803AC4E4 (92 bytes)
// _Rb_tree<unsigned short, pair<unsigned short, Room *>, ...>::_M_erase(...)
// Node size: 24
template <>
void _Rb_tree<unsigned short, pair<unsigned short, Room *>, _Select1st<pair<unsigned short, Room *> >, less<unsigned short>, allocator<pair<unsigned short, Room *> > >::_M_erase(_Rb_tree_node<pair<unsigned short, Room *> > * x) {
    while (x != 0) {
        _M_erase((_Rb_tree_node<pair<unsigned short, Room *> >*)(*(void**)((char*)x + 12)));
        _Rb_tree_node<pair<unsigned short, Room *> >* y = (_Rb_tree_node<pair<unsigned short, Room *> >*)(*(void**)((char*)x + 8));
        if (x) __node_alloc_M_deallocate(x, 24);
        x = y;
    }
}

// ---- Pattern B: _M_erase with BString destructor (104 bytes) ----

// 0x803A6884 (104 bytes)
// _Rb_tree<BString, pair<BString, unsigned int>, ...>::_M_erase(...)
// Calls BString::~BString(void) on element at node+16 before dealloc.
// Node size: 24
// This one calls ~BString on the key before deallocation.
// Keeping as inline asm because the destructor call is interleaved.
__attribute__((noreturn))
void _Rb_tree<BString, pair<BString, unsigned int>, _Select1st<pair<BString, unsigned int> >, less<BString>, allocator<pair<BString, unsigned int> > >::_M_erase(_Rb_tree_node<pair<BString, unsigned int> > *) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "mr	29,3\n"
        "mr.	31,4\n"
        "beq	.L_803A68D8\n"
        ".L_803A68A0:\n"
        "lwz	4,12(31)\n"
        "mr	3,29\n"
        ".long 0x4bffffdd  /* bl _Rb_tree<BString, ...>::_M_erase(...) */\n"
        "lwz	30,8(31)\n"
        "addi	3,31,16\n"
        "li	4,2\n"
        ".long 0x4bcf70dd  /* bl BString::~BString(void) */\n"
        "cmpwi	31,0\n"
        "beq	.L_803A68D0\n"
        "mr	3,31\n"
        "li	4,24\n"
        ".long 0x4bff5595  /* bl __node_alloc<false, 0>::_M_deallocate(void *, unsigned int) */\n"
        ".L_803A68D0:\n"
        "mr.	31,30\n"
        "bne	.L_803A68A0\n"
        ".L_803A68D8:\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// ---- Pattern C: _M_erase with CTilePt destructor (104 bytes) ----

// 0x803AC540 (104 bytes)
// _Rb_tree<CTilePt, pair<CTilePt, pair<DiagonalNode, DiagonalNode> >, ...>::_M_erase(...)
// Calls CTilePt::~CTilePt(void) on element at node+16 before dealloc.
// Node size: 36
__attribute__((noreturn))
void _Rb_tree<CTilePt, pair<CTilePt, pair<DiagonalNode, DiagonalNode> >, _Select1st<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > >, less<CTilePt>, allocator<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > > >::_M_erase(_Rb_tree_node<pair<CTilePt, pair<DiagonalNode, DiagonalNode> > > *) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "mr	29,3\n"
        "mr.	31,4\n"
        "beq	.L_803AC594\n"
        ".L_803AC55C:\n"
        "lwz	4,12(31)\n"
        "mr	3,29\n"
        ".long 0x4bffffdd  /* bl _Rb_tree<CTilePt, ...>::_M_erase(...) */\n"
        "lwz	30,8(31)\n"
        "addi	3,31,16\n"
        "li	4,2\n"
        ".long 0x4bd081b1  /* bl CTilePt::~CTilePt(void) */\n"
        "cmpwi	31,0\n"
        "beq	.L_803AC58C\n"
        "mr	3,31\n"
        "li	4,36\n"
        ".long 0x4bfef8d9  /* bl __node_alloc<false, 0>::_M_deallocate(void *, unsigned int) */\n"
        ".L_803AC58C:\n"
        "mr.	31,30\n"
        "bne	.L_803AC55C\n"
        ".L_803AC594:\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// ---- Pattern D: _M_erase with NamespaceSelector destructor (104 bytes) ----

// 0x803A6948 (104 bytes)
// _Rb_tree<unsigned int, pair<unsigned int, NamespaceSelector>, ...>::_M_erase(...)
// Calls NamespaceSelector::~NamespaceSelector(void) at node+20 before dealloc.
// Node size: 72
__attribute__((noreturn))
void _Rb_tree<unsigned int, pair<unsigned int, NamespaceSelector>, _Select1st<pair<unsigned int, NamespaceSelector> >, less<unsigned int>, allocator<pair<unsigned int, NamespaceSelector> > >::_M_erase(_Rb_tree_node<pair<unsigned int, NamespaceSelector> > *) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "mr	29,3\n"
        "mr.	31,4\n"
        "beq	.L_803A699C\n"
        ".L_803A6964:\n"
        "lwz	4,12(31)\n"
        "mr	3,29\n"
        ".long 0x4bffffdd  /* bl _Rb_tree<unsigned int, ...>::_M_erase(...) */\n"
        "lwz	30,8(31)\n"
        "addi	3,31,20\n"
        "li	4,2\n"
        ".long 0x4bd21455  /* bl NamespaceSelector::~NamespaceSelector(void) */\n"
        "cmpwi	31,0\n"
        "beq	.L_803A6994\n"
        "mr	3,31\n"
        "li	4,72\n"
        ".long 0x4bff54d1  /* bl __node_alloc<false, 0>::_M_deallocate(void *, unsigned int) */\n"
        ".L_803A6994:\n"
        "mr.	31,30\n"
        "bne	.L_803A6964\n"
        ".L_803A699C:\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
    __builtin_unreachable();
}


// ============================================================
// Rb_tree complex methods (insert_unique, _M_insert, insert_equal, _M_copy, operator=)
// ============================================================
// These remain in their original asm_decomp stub files:
//   - Rb_tree_L_int_pair_L_int_int_R_..._less_..._31e2f018.cpp (5 more functions)
//   - Rb_tree_L_int_pair_L_int_int_R_..._greater_..._00f2437a.cpp (2 more functions)
//   - Rb_tree_L_CasListener_ptr_..._c41a789c.cpp (2 more functions)
//   - Rb_tree_L_ERModel_ptr_..._65262c5b.cpp (3 more functions)
//   - Rb_tree_L_ERSoundEvent_ptr_..._a932b33f.cpp (2 more functions)
//   - Rb_tree_L_ResFile_ptr_..._dffab52d.cpp (3 more functions)
//   - Rb_tree_L_cTrack_ptr_..._5277abfd.cpp (3 more functions)
//   - Rb_tree_L_int_pair_L_int_cHitControlGroup_ptr_..._b4f641a0.cpp (3 more functions)
//   - Rb_tree_L_short_pair_L_short_bool_..._ee0fbdf1.cpp (3 more functions)
//   - Rb_tree_L_CTilePt_..._4ce6efb8.cpp (2 more functions)
//   - Rb_tree_L_pair_L_unsigned_int_ObjectDataID_..._9cd9be88.cpp (2 more functions)
//   - Rb_tree_L_unsigned_int_pair_L_unsigned_int_NamespaceSelector_..._a1f321b4.cpp (3 more functions)
//   - Rb_tree_L_unsigned_short_pair_L_unsigned_short_Room_ptr_..._2b5de8cb.cpp (2 more functions)
//   - Rb_tree_L_BString_..._a641f76e.cpp (0 more - only had _M_erase)
//   - Rb_tree_L_unsigned_int_pair_L_unsigned_int_iResFile_ptr_..._01f474a4.cpp (0 more - only had _M_erase)
//
// Total: ~33 complex Rb_tree functions remain in original files.


// ============================================================
// TArray<T, Alloc> -- 28 instantiations
// ============================================================
// TArray methods (Destruct, Deallocate, Construct, Copy, CopyReverse,
// SetSize, Insert, DeleteAll, FreeAll, SafeDeleteAll, Add, operator=)
// are complex with multiple internal calls, heap allocations via
// MainHeap()/EAHeap or EResourceManager, virtual destructor calls,
// and per-element copy/construct loops with type-specific strides.
//
// These remain in their original asm_decomp stub files:
//   - TArray_L_BSplineVolume_TArrayERModelAllocator_R.cpp
//   - TArray_L_EAnimEvent_TArrayERAnimAllocator_R.cpp
//   - TArray_L_EAnimNodeDataPos_TArrayERAnimAllocator_R.cpp
//   - TArray_L_EAnimNote_TArrayERAnimAllocator_R.cpp
//   - TArray_L_ECharacterNode_TArrayERCharacterAllocator_R.cpp
//   - TArray_L_EFileSystem_FileCreator_TArrayDefaultAllocator_R.cpp
//   - TArray_L_EFontPage_ptr_TArrayDefaultAllocator_R.cpp
//   - TArray_L_EILight_ptr_TArrayDefaultAllocator_R.cpp
//   - TArray_L_ENCameraPoint_TArrayDefaultAllocator_R.cpp
//   - TArray_L_ENCamera_TArrayERModelAllocator_R.cpp
//   - TArray_L_ENDummyPoint_TArrayDefaultAllocator_R.cpp
//   - TArray_L_ENDummy_TArrayERModelAllocator_R.cpp
//   - TArray_L_ENLatticePoints_TArrayDefaultAllocator_R.cpp
//   - TArray_L_ENLattice_TArrayERModelAllocator_R.cpp
//   - TArray_L_ESMSStrip_TArrayERModelAllocator_R.cpp
//   - TArray_L_EString2_TArrayDefaultAllocator_R.cpp
//   - TArray_L_EString_TArrayDefaultAllocator_R.cpp
//   - TArray_L_ESubModelShader_TArrayERModelAllocator_R.cpp
//   - TArray_L_ESubModel_TArrayERModelAllocator_R.cpp
//   - TArray_L_EVec3_TArrayDefaultAllocator_R.cpp
//   - TArray_L_SimsLightInfo_TArrayERModelAllocator_R.cpp
//   - TArray_L_SndEvtHitPatch_TArrayERSoundEventAllocator_R.cpp
//   - TArray_L_TArray_L_SndEvtHitPatch_TArrayERSoundEventAllocator_R_TArrayERSoundEventAllocator_R.cpp
//   - TArray_L_float_TArrayERAnimAllocator_R.cpp
//   - TArray_L_int_TArrayDefaultAllocator_R.cpp
//   - TArray_L_int_TArrayERCharacterAllocator_R.cpp
//   - TArray_L_unsigned_char_ptr_TArrayDefaultAllocator_R.cpp
//   - TArray_L_unsigned_int_TArrayDefaultAllocator_R.cpp


// ============================================================
// stack<T, Container> -- 4 instantiations
// ============================================================
// All 4 are destructors (~stack) that tear down the underlying deque.
// They copy the deque's iterator state into a large stack frame,
// call _Deque_base::~_Deque_base, then conditionally call __builtin_delete.
// Complex control flow -- remain in original asm_decomp files:
//   - stack_L_int_deque_L_int_allocator_L_int_R_R_R.cpp
//   - stack_L_FAMTarget_FAM_STATE_deque_..._R.cpp
//   - stack_L_MMUTarget_MMU_MENU_STATE_deque_..._R.cpp
//   - stack_L_StateMachineStatus_ptr_deque_..._R.cpp


// ============================================================
// _String_base<wchar_t, allocator<wchar_t> >::_M_allocate_block -- 1 instantiation
// ============================================================
// Allocates a string buffer: if size > 128, uses __builtin_new;
// otherwise uses __node_alloc::_M_allocate. Sets start/finish/end_of_storage.
// Remains in original asm_decomp file:
//   - String_base_L_wchar_t_allocator_L_wchar_t_R_R.cpp


// ============================================================
// byte_key_map<16, byte_key_map<72, short, ...>, ...>::~byte_key_map -- 1 instantiation
// ============================================================
// Destructor that walks the internal vector, deallocates each element's
// storage (choosing __builtin_delete vs __node_alloc based on size > 128),
// then deallocates the vector buffer itself.
// Remains in original asm_decomp file:
//   - byte_key_map_L_16_byte_key_map_L_72_short_..._77f3b8f4.cpp


// ============================================================
// _Base_bitset<3> -- 1 instantiation (2 functions)
// ============================================================
// _M_do_find_first and _M_do_find_next: bit-scanning algorithms
// using a lookup table at a hardcoded ROM address. Pure arithmetic,
// no function calls, but uses bctr-style counted loops and ROM table
// lookups that cannot be faithfully reproduced in C++.
// Remains in original asm_decomp file:
//   - Base_bitset_L_3_R.cpp
