// esim.cpp - ESim class (main simulation entity)
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(esim.obj)
//
// Small functions (<=64 bytes) decompiled from the esim object file.

#include "types.h"

// Forward declarations
class EStream;
class EFile;
class EStorable;
class ETypeInfo;
class ESim;
class ESimsCam;

// External functions
extern EStream& EStorable_StreamOut(EStream& stream, EStorable* obj);
extern EStream& EStorable_StreamIn(EStream& stream, EStorable*& obj);
extern EFile& EStorable_FileIn(EFile& file, EStorable*& obj);
extern void* EAHeap_GetCurrentHeap();
extern void* EAHeap_Alloc(void* heap, u32 size, int align);
extern void EAHeap_Free(void* heap, void* ptr);

// ESim type info
extern ETypeInfo ESim_typeInfo;
extern const char* ESim_typeName;
extern u32 ESim_typeKey;
extern u16 ESim_readVersion;

// ESim class layout (partial)
// 0x03D0 = ISimInstance ptr (used by IsDog/IsCat/IsMonkey etc.)

//=============================================================================
// operator<<(EStream&, ESim*)
// Address: 0x80030A24, Size: 32
//=============================================================================
EStream& operator<<(EStream& stream, ESim* sim) {
    return EStorable_StreamOut(stream, (EStorable*)sim);
}

//=============================================================================
// operator>>(EStream&, ESim*&)
// Address: 0x80030A44, Size: 64
//=============================================================================
EStream& operator>>(EStream& stream, ESim*& sim) {
    EStorable* tmp;
    EStorable_StreamIn(stream, tmp);
    sim = (ESim*)tmp;
    return stream;
}

//=============================================================================
// operator>>(EFile&, ESim*&)
// Address: 0x80030A84, Size: 64
//=============================================================================
EFile& operator>>(EFile& file, ESim*& sim) {
    EStorable* tmp;
    EStorable_FileIn(file, tmp);
    sim = (ESim*)tmp;
    return file;
}

class ESim {
public:
    u8 pad00[0x03D0];
    void* m_simInstance;  // 0x03D0

    // IsDog - virtual dispatch through ISimInstance
    // Address: 0x8003185C, Size: 56
    // NON_MATCHING - virtual dispatch
    bool IsDog();

    // IsCat - virtual dispatch through ISimInstance
    // Address: 0x80031894, Size: 56
    // NON_MATCHING - virtual dispatch
    bool IsCat();

    // IsMonkey - virtual dispatch through ISimInstance
    // Address: 0x800318CC, Size: 56
    // NON_MATCHING - virtual dispatch
    bool IsMonkey();

    // ESim type info accessors
    const ETypeInfo* GetTypeInfo() const { return &ESim_typeInfo; }
    const char* GetTypeName() const { return ESim_typeName; }
    u32 GetTypeKey() const { return ESim_typeKey; }
    u16 GetTypeVersion() const { return ESim_readVersion; }
    static const ETypeInfo* GetTypeInfoStatic() { return &ESim_typeInfo; }
    static u16 GetReadVersion() { return ESim_readVersion; }

    // operator new (placement)
    static void* operator new(unsigned int, void* p) { return p; }

    // operator delete
    static void operator delete(void* ptr) {
        void* heap = EAHeap_GetCurrentHeap();
        EAHeap_Free(heap, ptr);
    }

    // SafeDelete
    // NON_MATCHING - virtual dispatch
    void SafeDelete();

    // CreateCopy
    // NON_MATCHING - calls global CreateCopy
    ESim* CreateCopy() const;
};

//=============================================================================
// ESimsScratchpadMan - scratch memory manager for sims
// Address range: 0x800353D4-0x80035460
// Original: esimscratchpadman.obj
//=============================================================================

// ESimsScratchpadMan::operator new
// Address: 0x800353D4, Size: 56
void* ESimsScratchpadMan_New(u32 size) {
    void* heap = EAHeap_GetCurrentHeap();
    return EAHeap_Alloc(heap, size, 0);
}

// ESimsScratchpadMan::operator delete
// Address: 0x8003540C, Size: 52
void ESimsScratchpadMan_Delete(void* ptr) {
    void* heap = EAHeap_GetCurrentHeap();
    EAHeap_Free(heap, ptr);
}
