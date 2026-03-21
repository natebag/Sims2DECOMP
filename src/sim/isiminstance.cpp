// isiminstance.cpp - ISimInstance, IBaseSimInstance
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(isiminstance.obj)
//
// Small functions (<=64 bytes) decompiled from the isiminstance object file.
// ISimInstance is the interface for sim placement/rendering in the world.

#include "types.h"

// Forward declarations
class EStream;
class EFile;
class EStorable;
class ETypeInfo;
class EHouse;
class ERLevel;
class cXObject;
class ISimInstance;

// External functions
extern EStream& EStorable_StreamOut(EStream& stream, EStorable* obj);
extern EStream& EStorable_StreamIn(EStream& stream, EStorable*& obj);
extern EFile& EStorable_FileIn(EFile& file, EStorable*& obj);
extern void* EAHeap_GetCurrentHeap();
extern void EAHeap_Free(void* heap, void* ptr);

// Type info
extern ETypeInfo ISimInstance_typeInfo;
extern const char* ISimInstance_typeName;
extern u32 ISimInstance_typeKey;
extern u16 ISimInstance_readVersion;

//=============================================================================
// Streaming operators
//=============================================================================

// operator<<(EStream&, ISimInstance*)
// Address: 0x80056254, Size: 32
EStream& operator<<(EStream& stream, ISimInstance* inst) {
    return EStorable_StreamOut(stream, (EStorable*)inst);
}

// operator>>(EStream&, ISimInstance*&)
// Address: 0x80056274, Size: 64
EStream& operator>>(EStream& stream, ISimInstance*& inst) {
    EStorable* tmp;
    EStorable_StreamIn(stream, tmp);
    inst = (ISimInstance*)tmp;
    return stream;
}

// operator>>(EFile&, ISimInstance*&)
// Address: 0x800562B4, Size: 64
EFile& operator>>(EFile& file, ISimInstance*& inst) {
    EStorable* tmp;
    EStorable_FileIn(file, tmp);
    inst = (ISimInstance*)tmp;
    return file;
}

//=============================================================================
// ISimInstance - empty virtual stubs (all just blr)
//=============================================================================
class ISimInstance {
public:
    // All these are empty virtual stubs (just blr = 4 bytes each)
    // Address: 0x8005631C-0x800563D0

    void Create(cXObject*, EHouse*) {}              // 0x8005631C
    void OrentSubObject(cXObject*) {}               // 0x80056320
    void SetObjOrient() {}                          // 0x80056324
    void CreateShadow() {}                          // 0x80056328
    void InsertSubModelsInHouse(ERLevel*) {}         // 0x8005632C
    void RemoveSubModelsFromHouse(ERLevel*) {}       // 0x80056330
    void PropigateFlagsToSubModels() {}             // 0x80056334
    void SetOutOfWorld() {}                         // 0x80056338
    void SetCarryOrient() {}                        // 0x8005633C
    void SetCarryPos() {}                           // 0x80056340
    void SetLevel(int) {}                           // 0x80056344
    void SetAnim() {}                               // 0x80056348
    void AnimDone() {}                              // 0x8005634C
    void SetNormalColorMix(float) {}                // 0x80056350
    void FadeOutShadow() {}                         // 0x80056354
    void FadeInShadow() {}                          // 0x80056358
    void SetBoundingBoxForCollisionMaps() {}        // 0x8005635C
    void EnableVibration(bool) {}                   // 0x80056360
    void DisableDraw(bool) {}                       // 0x80056364
    void UpdateCollisionMap() {}                    // 0x80056368
    void MoveModel(float, float, float, float) {}   // 0x8005636C
    void UpdateFootprint() {}                       // 0x80056370
    void SetShadowVisibility(bool) {}               // 0x80056374
    void SetTransformedBoundingBox() {}             // 0x80056378
    void SnapToGround() {}                          // 0x8005637C
    void OnShelfItemAdd() {}                        // 0x80056380
    void OnShelfItemRemove() {}                     // 0x80056384
    void UpdateModelPositionFromXObject() {}        // 0x80056388
    void UpdateRoomID() {}                          // 0x8005638C
    void SetTileTexture() {}                        // 0x80056390

    // SetPlacementError
    // Address: 0x800562F4, Size: 40
    // NON_MATCHING - virtual dispatch
    void SetPlacementError(bool val);

    // SetHighlight
    // Address: 0x8005656C, Size: 40
    // NON_MATCHING - virtual dispatch
    void SetHighlight(unsigned int idx, bool val);

    // Type info
    const ETypeInfo* GetTypeInfo() const { return &ISimInstance_typeInfo; }
    const char* GetTypeName() const { return ISimInstance_typeName; }
    u32 GetTypeKey() const { return ISimInstance_typeKey; }
    u16 GetTypeVersion() const { return ISimInstance_readVersion; }
    static const ETypeInfo* GetTypeInfoStatic() { return &ISimInstance_typeInfo; }
    static u16 GetReadVersion() { return ISimInstance_readVersion; }

    // operator delete
    static void operator delete(void* ptr) {
        void* heap = EAHeap_GetCurrentHeap();
        EAHeap_Free(heap, ptr);
    }
};
