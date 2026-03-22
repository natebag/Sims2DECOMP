// e_animnodedatapos.cpp - EAnimNodeDataPos (animation node position data)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(e_animnodedatapos.obj)
//
// Small functions (<=64 bytes) decompiled from the e_animnodedatapos object file.

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class EStream;
class EFile;
class EStorable;
class ETypeInfo;
class EAnimNodeDataPos;

// External functions
extern EStream& EStorable_StreamOut(EStream& stream, EStorable* obj);
extern EStream& EStorable_StreamIn(EStream& stream, EStorable*& obj);
extern EFile& EStorable_FileIn(EFile& file, EStorable*& obj);
extern void* EAHeap_GetCurrentHeap();
extern void EAHeap_Free(void* heap, void* ptr);

// Type info
extern ETypeInfo EAnimNodeDataPos_typeInfo;

// Placement new
inline void* operator new(unsigned int, void* ptr) { return ptr; }

//=============================================================================
// Streaming operators
//=============================================================================
EStream& operator<<(EStream& stream, EAnimNodeDataPos* obj) {
    return EStorable_StreamOut(stream, (EStorable*)obj);
}

EStream& operator>>(EStream& stream, EAnimNodeDataPos*& obj) {
    EStorable* tmp;
    EStorable_StreamIn(stream, tmp);
    obj = (EAnimNodeDataPos*)tmp;
    return stream;
}

EFile& operator>>(EFile& file, EAnimNodeDataPos*& obj) {
    EStorable* tmp;
    EStorable_FileIn(file, tmp);
    obj = (EAnimNodeDataPos*)tmp;
    return file;
}

//=============================================================================
// EAnimNodeDataPos
//=============================================================================
class EAnimNodeDataPos {
public:
    // Type info
    const ETypeInfo* GetTypeInfo() const { return &EAnimNodeDataPos_typeInfo; }
    static const ETypeInfo* GetTypeInfoStatic() { return &EAnimNodeDataPos_typeInfo; }

    // operator new (placement)
    static void* operator new(unsigned int, void* p) { return p; }

    // operator delete
    static void operator delete(void* ptr) {
        void* heap = EAHeap_GetCurrentHeap();
        EAHeap_Free(heap, ptr);
    }

    // SafeDelete, CreateCopy, New, Construct, Destruct - standard patterns
    // NON_MATCHING - each follows the storable type pattern
    void SafeDelete();
    EAnimNodeDataPos* CreateCopy() const;
    static EAnimNodeDataPos* New();
    static void Construct(EAnimNodeDataPos* ptr);
    static void Destruct(EAnimNodeDataPos* ptr);
};
