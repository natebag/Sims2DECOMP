#ifndef OBJDEFINITION_H
#define OBJDEFINITION_H

#include "types.h"

// Forward declarations
class StringBuffer;
class iResFile;

namespace Memory {
    class HandleNode;
}

// ============================================================================
// ObjDefinition - Object definition data from IFF resources
// Contains multi-tile offsets and sub-index encoding
// Object file: objdefinition.obj
// ============================================================================
struct ObjDefinition {
    // Layout includes:
    // +0x16: short - packed multi-tile offsets (high byte = X, low byte = Y)
    // +0x17: byte - Y offset (low byte of the short at +0x16)

    void Swizzle(void* data, int size);
    void GetMultiTileOffsets(int* outX, int* outY) const;
    static short GetSubIndex(int x, int y);
};

// ============================================================================
// ObjectDataObjDefinition - Wrapper around ObjDefinition with ref counting
// Size: 0x20
// Vtable at 0x80465938
// Object file: objdefinition.obj (actually in objectdataobjdefinition.obj)
//
// Layout:
//   +0x00: vtable pointer
//   +0x04: unknown
//   +0x08: unknown
//   +0x0C: unknown
//   +0x10: unknown
//   +0x14: int m_refCount
//   +0x18: short m_resID
//   +0x1A: byte m_attached (bool)
//   +0x1C: ObjDefinition* m_data
// ============================================================================
class ObjectDataObjDefinition {
public:
    /* +0x00 */ void* m_vtable;
    /* +0x04 */ u32 m_field_04;
    /* +0x08 */ u32 m_field_08;
    /* +0x0C */ u32 m_field_0C;
    /* +0x10 */ u32 m_field_10;
    /* +0x14 */ int m_refCount;
    /* +0x18 */ short m_resID;
    /* +0x1A */ u8 m_attached;
    /* +0x1B */ u8 m_pad;
    /* +0x1C */ ObjDefinition* m_data;

    ObjectDataObjDefinition(void);
    ObjectDataObjDefinition(ObjectDataObjDefinition& other);
    ~ObjectDataObjDefinition(void);

    void Reset(void);
    void Detach(void);
    void ResetResData(void);

    ObjectDataObjDefinition& operator=(ObjectDataObjDefinition& other);
    ObjectDataObjDefinition& operator=(ObjDefinition& def);

    int GetResDataName(unsigned int type, short id, StringBuffer& name) const;
    int SetResDataName(unsigned int type, short id, char* name);

    void GetResourceName(StringBuffer* name) const;
    void SetResourceName(StringBuffer* name);
    unsigned int GetResourceType(void) const;

    void SetOwnDefinition(ObjDefinition* def);

    int LoadFromQDataByID(unsigned int type, short id);
    int LoadFromIFFByID(unsigned int type, short id);
    int SaveToIFFFile(unsigned int type, short id, StringBuffer& name);

    int LoadFromDBByID(unsigned int type, short id);
    int SaveToDB(unsigned int type, short id, StringBuffer& name);

    int QueryInterface(unsigned int iid, void** out);
    int AddRef(void);
    int Release(void);

    short GetResID(void) const;
    void SetResID(short id);
    ObjDefinition* GetData(void);
    const ObjDefinition* GetData(void) const;
};

#endif // OBJDEFINITION_H
