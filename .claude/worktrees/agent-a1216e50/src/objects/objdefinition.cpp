// objdefinition.cpp - Object definition and ObjectDataObjDefinition
// Object files: objdefinition.obj, objectdataobjdefinition.obj
//
// All small functions (<=64 bytes) decompiled.

#include "objects/objdefinition.h"

// External functions
extern void StringBuffer_Clear(StringBuffer& buf); // 0x800a6610

// ============================================================================
// ObjDefinition methods
// ============================================================================

// ObjDefinition::Swizzle - No-op swizzle (stub)
// 0x800D942C (size=4)
void ObjDefinition::Swizzle(void* data, int size) {
}

// ObjDefinition::GetMultiTileOffsets - Extract X/Y tile offsets from packed short
// 0x800D9430 (size=24)
// Offset +0x16 is a short: high byte = X offset (signed), low byte = Y offset
void ObjDefinition::GetMultiTileOffsets(int* outX, int* outY) const {
    short packed = *(short*)((char*)this + 0x16);
    *outX = packed >> 8;                                    // sign-extend high byte
    *outY = *(unsigned char*)((char*)this + 0x17);          // low byte, zero-extend
}

// ObjDefinition::GetSubIndex - Pack X/Y into a sub-index short
// 0x800D9448 (size=20)
// Static function: takes x in r3 (first param) and y in r4 (second param)
short ObjDefinition::GetSubIndex(int x, int y) {
    return (short)((x << 8) | (y & 0xFF));
}

// ============================================================================
// ObjectDataObjDefinition methods
// ============================================================================

// ObjectDataObjDefinition::Detach - Clear attached flag
// 0x8015BEDC (size=12)
void ObjectDataObjDefinition::Detach(void) {
    m_attached = 0;
}

// ObjectDataObjDefinition::ResetResData - No-op (stub)
// 0x8015BF30 (size=4)
void ObjectDataObjDefinition::ResetResData(void) {
}

// ObjectDataObjDefinition::GetResDataName - Clears buffer, returns 0
// 0x8015C0E8 (size=40)
int ObjectDataObjDefinition::GetResDataName(unsigned int type, short id, StringBuffer& name) const {
    StringBuffer_Clear(name);
    return 0;
}

// ObjectDataObjDefinition::SetResDataName - Returns 0 (not supported)
// 0x8015C110 (size=8)
int ObjectDataObjDefinition::SetResDataName(unsigned int type, short id, char* name) {
    return 0;
}

// ObjectDataObjDefinition::GetResourceType - Returns 'OBJD' as FourCC
// 0x8015C1E8 (size=12)
unsigned int ObjectDataObjDefinition::GetResourceType(void) const {
    return 0x4F424A44; // 'OBJD'
}

// ObjectDataObjDefinition::LoadFromDBByID - Not supported, returns 0
// 0x8015C6F8 (size=8)
int ObjectDataObjDefinition::LoadFromDBByID(unsigned int type, short id) {
    return 0;
}

// ObjectDataObjDefinition::SaveToDB - Not supported, returns 0
// 0x8015C700 (size=8)
int ObjectDataObjDefinition::SaveToDB(unsigned int type, short id, StringBuffer& name) {
    return 0;
}

// ObjectDataObjDefinition::AddRef - Increment reference count, return new value
// 0x8015C778 (size=20)
int ObjectDataObjDefinition::AddRef(void) {
    m_refCount++;
    return m_refCount;
}

// ObjectDataObjDefinition::GetResID
// 0x8015CA24 (size=8)
short ObjectDataObjDefinition::GetResID(void) const {
    return m_resID;
}

// ObjectDataObjDefinition::SetResID
// 0x8015CA2C (size=8)
void ObjectDataObjDefinition::SetResID(short id) {
    m_resID = id;
}

// ObjectDataObjDefinition::GetData (non-const)
// 0x8015CA34 (size=8)
ObjDefinition* ObjectDataObjDefinition::GetData(void) {
    return m_data;
}

// ObjectDataObjDefinition::GetData (const)
// 0x8015CA3C (size=8)
const ObjDefinition* ObjectDataObjDefinition::GetData(void) const {
    return m_data;
}
