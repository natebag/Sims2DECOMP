// behaviortree.cpp - Behavior tree data structures
// Object file: behaviortree.obj
// Small functions (<= 64 bytes) decompiled from Sims 2 GameCube
//
// Matching status (devkitPPC GCC vs original SN Systems):
//   MATCHING: GetStructVersion, GetNumNodes, GetType, SetType
//   MATCHING: SetNumParams, SetNumLocals, GetTreeVersion, SetTreeVersion
//   MATCHING: GetResID, SetResID
//   MATCHING: ResourceBehaviorTree::SaveDataByID
//   MATCHING: ResourceBehaviorTree::GetDataSourceType, IFFBehaviorTree::GetDataSourceType
//   NON_MATCHING: GetNode (GCC optimizes (idx*12)+12 to (idx+1)*12)
//   NON_MATCHING: ~ObjectDataBehaviorTree (destructor codegen)
//   NON_MATCHING: SetResourceName (depends on StringBuffer)
//   NON_MATCHING: AddRef functions (register alloc)
//   NON_MATCHING: Virtual dispatch thunks
//   NON_MATCHING: GetDataID (depends on ObjectDataID copy)
//   NON_MATCHING: Global constructors/destructors

#include "sim/behaviortree.h"

// External functions
// StringBuffer::CopyFrom at 0x800A6768
extern void StringBuffer_CopyFrom(void* dst, void* src);
// ObjectDataID::CopyFrom at 0x8015BB04
extern void ObjectDataID_Init(void* dst, int a, int b);
// __static_initialization_and_destruction_0 at 0x8015B8F8
extern void __static_initialization_and_destruction_0_behaviortree(int, int);
// operator delete at 0x802D1220
extern void operator_delete(void* ptr);

// ============================================================================
// ObjectDataBehaviorTree::~ObjectDataBehaviorTree - Virtual destructor
// Address: 0x8015A990 | Size: 52 bytes
// Sets vtable to ObjectDataBehaviorTree vtable, conditionally deletes
// NON_MATCHING - GCC destructor codegen differs from SN Systems
// ============================================================================
ObjectDataBehaviorTree::~ObjectDataBehaviorTree() {
    // Compiler generates vtable store + conditional delete
}

// ============================================================================
// ObjectDataBehaviorTree::SetResourceName - Copy name from StringBuffer
// Address: 0x8015AAD4 | Size: 40 bytes
// Calls StringBuffer::CopyFrom on this+0x0C, returns 1
// ============================================================================
// NON_MATCHING - depends on StringBuffer::CopyFrom implementation
int ObjectDataBehaviorTree::SetResourceName(StringBuffer& buf) {
    // StringBuffer_CopyFrom(&m_name, &buf);
    return 1;
}

// ============================================================================
// ObjectDataBehaviorTree::GetStructVersion - Read struct version from header
// Address: 0x8015AAFC | Size: 12 bytes
// lwz r9,84(r3); lha r3,0(r9); blr
// ============================================================================
short ObjectDataBehaviorTree::GetStructVersion() const {
    return m_pHeader->m_structVersion;
}

// ============================================================================
// ObjectDataBehaviorTree::GetNumNodes - Read node count from header
// Address: 0x8015AB08 | Size: 12 bytes
// lwz r9,84(r3); lha r3,2(r9); blr
// ============================================================================
short ObjectDataBehaviorTree::GetNumNodes() const {
    return m_pHeader->m_numNodes;
}

// ============================================================================
// ObjectDataBehaviorTree::GetType - Read type byte from header
// Address: 0x8015AB14 | Size: 12 bytes
// lwz r9,84(r3); lbz r3,4(r9); blr
// ============================================================================
u8 ObjectDataBehaviorTree::GetType() const {
    return m_pHeader->m_type;
}

// ============================================================================
// ObjectDataBehaviorTree::SetType - Write type byte to header
// Address: 0x8015AB20 | Size: 12 bytes
// lwz r9,84(r3); stb r4,4(r9); blr
// ============================================================================
void ObjectDataBehaviorTree::SetType(u8 type) {
    m_pHeader->m_type = type;
}

// ============================================================================
// ObjectDataBehaviorTree::SetNumParams - Write numParams byte to header
// Address: 0x8015AB94 | Size: 12 bytes
// lwz r9,84(r3); stb r4,5(r9); blr
// ============================================================================
void ObjectDataBehaviorTree::SetNumParams(u8 params) {
    m_pHeader->m_numParams = params;
}

// ============================================================================
// ObjectDataBehaviorTree::SetNumLocals - Write numLocals byte to header
// Address: 0x8015AC10 | Size: 12 bytes
// lwz r9,84(r3); stb r4,6(r9); blr
// ============================================================================
void ObjectDataBehaviorTree::SetNumLocals(u8 locals) {
    m_pHeader->m_numLocals = locals;
}

// ============================================================================
// ObjectDataBehaviorTree::GetTreeVersion - Read treeVersion byte from header
// Address: 0x8015AC1C | Size: 12 bytes
// lwz r9,84(r3); lbz r3,11(r9); blr
// Reads byte at header+0x0B
// ============================================================================
u8 ObjectDataBehaviorTree::GetTreeVersion() const {
    return *((u8*)m_pHeader + 0x0B);
}

// ============================================================================
// ObjectDataBehaviorTree::SetTreeVersion - Write treeVersion int to header
// Address: 0x8015AC28 | Size: 12 bytes
// lwz r9,84(r3); stw r4,8(r9); blr
// Stores full int at header+0x08 (byte at +0x0B is high byte on BE)
// ============================================================================
void ObjectDataBehaviorTree::SetTreeVersion(u8 version) {
    m_pHeader->m_treeVersionData = (int)version;
}

// ============================================================================
// ObjectDataBehaviorTree::GetNode - Get pointer to nth node
// Address: 0x8015AC34 | Size: 20 bytes
// mulli r4,r4,12; lwz r3,84(r3); addi r4,r4,12; add r3,r3,r4; blr
// Returns pointer to header + 12 + index * 12
// NON_MATCHING - GCC optimizes (index*12)+12 to (index+1)*12
// ============================================================================
BehaviorNode* ObjectDataBehaviorTree::GetNode(unsigned int index) const {
    return (BehaviorNode*)((char*)m_pHeader + 12 + index * 12);
}

// ============================================================================
// ObjectDataBehaviorTree::GetResID - Return resource ID (sign-extended short)
// Address: 0x8015AC48 | Size: 8 bytes
// lha r3,4(r3); blr
// ============================================================================
short ObjectDataBehaviorTree::GetResID() const {
    return m_resID;
}

// ============================================================================
// ObjectDataBehaviorTree::SetResID - Set resource ID
// Address: 0x8015AC50 | Size: 8 bytes
// sth r4,4(r3); blr
// ============================================================================
void ObjectDataBehaviorTree::SetResID(short id) {
    m_resID = id;
}

// ============================================================================
// ResourceBehaviorTree::LoadOnlyNameAndIDFromIndex - Virtual dispatch
// Address: 0x8015ADE8 | Size: 52 bytes
// Reads own vtable, calls vtable[0x30/0x34] (parent's LoadOnlyNameAndIDFromIndex)
// ============================================================================
// NON_MATCHING - virtual dispatch through own vtable

// ============================================================================
// ResourceBehaviorTree::SaveDataByID - Stub, always returns 0
// Address: 0x8015B06C | Size: 8 bytes
// li r3,0; blr
// ============================================================================
int ResourceBehaviorTree::SaveDataByID(ObjectDataID& id) {
    return 0;
}

// ============================================================================
// ResourceBehaviorTree::AddRef - Increment reference count at +0x64
// Address: 0x8015B268 | Size: 20 bytes
// NON_MATCHING - register allocation (original uses mr r9,r3 first, GCC loads first)
// ============================================================================
int ResourceBehaviorTree::AddRef() {
    m_refCount++;
    return m_refCount;
}

// ============================================================================
// IFFBehaviorTree::LoadOnlyNameAndIDFromIndex - Virtual dispatch
// Address: 0x8015B4F0 | Size: 52 bytes
// Reads own vtable, calls vtable[0x30/0x34] (parent's LoadOnlyNameAndIDFromIndex)
// ============================================================================
// NON_MATCHING - virtual dispatch through own vtable

// ============================================================================
// IFFBehaviorTree::GetFromDataID - Virtual dispatch
// Address: 0x8015B61C | Size: 52 bytes
// Reads own vtable, calls vtable[0x28/0x2C]
// ============================================================================
// NON_MATCHING - virtual dispatch through own vtable

// ============================================================================
// IFFBehaviorTree::AddRef - Increment reference count at +0x60
// Address: 0x8015B888 | Size: 20 bytes
// NON_MATCHING - register allocation (original uses mr r9,r3 first, GCC loads first)
// ============================================================================
int IFFBehaviorTree::AddRef() {
    m_refCount++;
    return m_refCount;
}

// ============================================================================
// ObjectDataBehaviorTree::GetDataID - Copy DataID to output
// Address: 0x8015B968 | Size: 52 bytes
// Adjusts output pointer by +88 (0x58), calls copy function
// ============================================================================
// NON_MATCHING - depends on ObjectDataID copy function at 0x8015BB04
void ObjectDataBehaviorTree::GetDataID(ObjectDataID& outID) const {
    // Copies m_dataID (at this+0x58) to outID
    // Uses external copy function
}

// ============================================================================
// ResourceBehaviorTree::GetDataSourceType - Returns 8 (resource type)
// Address: 0x8015B99C | Size: 8 bytes
// li r3,8; blr
// ============================================================================
int ResourceBehaviorTree::GetDataSourceType() const {
    return 8;
}

// ============================================================================
// IFFBehaviorTree::GetDataSourceType - Returns 2 (IFF type)
// Address: 0x8015B9A4 | Size: 8 bytes
// li r3,2; blr
// ============================================================================
int IFFBehaviorTree::GetDataSourceType() const {
    return 2;
}

// ============================================================================
// global constructors keyed to ObjectDataBehaviorTree::ObjectDataBehaviorTree(void)
// Address: 0x8015B9AC | Size: 44 bytes
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// ============================================================================
// NON_MATCHING - compiler-generated global constructor thunk

// ============================================================================
// global destructors keyed to ObjectDataBehaviorTree::ObjectDataBehaviorTree(void)
// Address: 0x8015B9D8 | Size: 44 bytes
// Calls __static_initialization_and_destruction_0(0, 0xFFFF)
// ============================================================================
// NON_MATCHING - compiler-generated global destructor thunk
