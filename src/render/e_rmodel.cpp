// e_rmodel.cpp - ERModel (model resource)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(e_rmodel.obj)
//
// Small functions (<=64 bytes) decompiled from the e_rmodel object file.
// ERModel is the resource class for 3D models.

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class EStream;
class EFile;
class EStorable;
class ETypeInfo;
class ERModel;

// External functions
extern EStream& EStorable_StreamOut(EStream& stream, EStorable* obj);
extern EStream& EStorable_StreamIn(EStream& stream, EStorable*& obj);
extern EFile& EStorable_FileIn(EFile& file, EStorable*& obj);
extern void* EAHeap_GetCurrentHeap();
extern void EAHeap_Free(void* heap, void* ptr);

// Type info
extern ETypeInfo ERModel_typeInfo;
extern const char* ERModel_typeName;
extern u32 ERModel_typeKey;
extern u16 ERModel_readVersion;

// Placement new
inline void* operator new(unsigned int, void* ptr) { return ptr; }

//=============================================================================
// Streaming operators
//=============================================================================

// operator<<(EStream&, ERModel*)
// Address: 0x80317D4C, Size: 32
EStream& operator<<(EStream& stream, ERModel* model) {
    return EStorable_StreamOut(stream, (EStorable*)model);
}

// operator>>(EStream&, ERModel*&)
// Address: 0x80317D6C, Size: 64
EStream& operator>>(EStream& stream, ERModel*& model) {
    EStorable* tmp;
    EStorable_StreamIn(stream, tmp);
    model = (ERModel*)tmp;
    return stream;
}

// operator>>(EFile&, ERModel*&)
// Address: 0x80317DAC, Size: 64
EFile& operator>>(EFile& file, ERModel*& model) {
    EStorable* tmp;
    EStorable_FileIn(file, tmp);
    model = (ERModel*)tmp;
    return file;
}

//=============================================================================
// ERModel
//=============================================================================
class ERModel {
public:
    u8 pad00[0x80];

    // Type info
    const ETypeInfo* GetTypeInfo() const { return &ERModel_typeInfo; }
    const char* GetTypeName() const { return ERModel_typeName; }
    u32 GetTypeKey() const { return ERModel_typeKey; }
    u16 GetTypeVersion() const { return ERModel_readVersion; }
    static const ETypeInfo* GetTypeInfoStatic() { return &ERModel_typeInfo; }
    static u16 GetReadVersion() { return ERModel_readVersion; }

    // operator new (placement)
    static void* operator new(unsigned int, void* p) { return p; }

    // operator delete
    static void operator delete(void* ptr) {
        void* heap = EAHeap_GetCurrentHeap();
        EAHeap_Free(heap, ptr);
    }

    // Refresh
    // Address: 0x803180F4, Size: 40
    // NON_MATCHING - file read pattern
    void Refresh(EFile* file);

    // GetShaderCount
    // Address: 0x80318778, Size: 52
    // NON_MATCHING - indirect access
    int GetShaderCount();

    // SafeDelete
    // NON_MATCHING - virtual dispatch
    void SafeDelete();

    // CreateCopy
    // NON_MATCHING - copy pattern
    ERModel* CreateCopy() const;

    // New
    // NON_MATCHING - alloc pattern
    static ERModel* New();

    // Construct
    // NON_MATCHING - placement new
    static void Construct(ERModel* ptr);

    // Destruct
    // NON_MATCHING - virtual dispatch
    static void Destruct(ERModel* ptr);
};
