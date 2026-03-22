// ============================================================================
// objectmodule.cpp - Object module, folder, iterator, fn table, test sim,
//                    stub object, and error handling implementations
// Object files: objectmodule.obj, objectfolder.obj, objectiterator.obj,
//               objfntable.obj, objtestsim.obj, stubobject.obj, objecterr.obj
// All small functions (<=64 bytes) from the DVD map
// ============================================================================

#include "objects/objectmodule.h"
#include "types.h"

// External functions
extern void* operator new(u32 size);
extern void operator delete(void* ptr);

// External r13-relative globals
extern ObjectFolder* gpObjectFolder;    // r13 - 31848 (0x8398)
extern ObjectModule* gpObjectModule;    // r13 - 21508 (0xABFC -> for GetFolder)
extern cXObject* gpSimObject;           // r13 - 21496 (0xAC08)
extern void* gpSelectedPeople;          // r13 - 21432 (0xAC48)

// External functions called by these implementations
extern void AdvanceSelectedPerson_impl(int direction); // 0x80040cc8
extern cXObject* GetSelectedPerson_impl(int index);    // 0x8004079c

// ============================================================================
// objecterr.obj functions
// ============================================================================

// cXObjectImpl::GetErrorString(StringBuffer &) - 0x800ebe38 (36 bytes)
// NON_MATCHING - calls StringBuffer method, passes r4 as r3
// Calls 0x800a6610 which is likely StringBuffer::append or similar
void cXObjectImpl_GetErrorString(cXObjectImpl* self, StringBuffer* buf) {
    // Original: mr r3,r4; bl StringBuffer::method
    // Delegates to StringBuffer function
}

// ============================================================================
// objectfolder.obj functions
// ============================================================================

// ObjectFolder::CreateInstance(void) - 0x800ebf94 (40 bytes)
// NON_MATCHING - GCC generates different new+ctor inlining pattern
ObjectFolder* ObjectFolder::CreateInstance(void) {
    ObjectFolderImpl* impl = new ObjectFolderImpl();
    return impl;
}

// ObjectFolder::DestroyInstance(ObjectFolder *) - 0x800ebfbc (64 bytes)
// NON_MATCHING - original uses vtable this-adjust + blrl pattern
void ObjectFolder::DestroyInstance(ObjectFolder* folder) {
    if (folder) {
        delete folder;
    }
}

// GlobalConstantsClient::GlobalConstantsClient(short) - 0x800ec068 (20 bytes)
// lis r9,vtable_hi; sth r4,4(r3); addi r9,vtable_lo; stw r9,0(r3); blr
GlobalConstantsClient::GlobalConstantsClient(short fileID) {
    m_id = fileID;
}

// GlobalConstantsClient::GetFileID(void) - 0x800ec07c (8 bytes)
// lwz r3,-31848(r13); blr
// Returns a global ObjectFolder pointer stored in r13-relative
short GlobalConstantsClient::GetFileID(void) {
    return 0; // NON_MATCHING - loads from r13-relative global
}

// GlobalConstantsClient::GetID(void) - 0x800ec084 (8 bytes)
// lha r3,4(r3); blr
short GlobalConstantsClient::GetID(void) {
    return m_id;
}

// LDtraceNull(...) - 0x800ee2b0 (4 bytes)
// blr
void LDtraceNull(...) {
}

// ObjectFolderImpl::DeletingInstance(ObjSelector *) - 0x800efd90 (52 bytes)
// Decrements refcount at +0x68 in selector, calls cleanup at 0
// NON_MATCHING - register allocation differs
void ObjectFolderImpl::DeletingInstance(ObjSelector* sel) {
    int* refCount = (int*)((char*)sel + 0x68);
    (*refCount)--;
    if (*refCount == 0) {
        // calls 0x800f111c - some cleanup function
    }
}

// ObjectFolderImpl::CreatingResFile(iResFile *) - 0x800efdc4 (4 bytes)
// blr
void ObjectFolderImpl::CreatingResFile(iResFile* file) {
}

// ObjectFolderImpl::DeletingResFile(iResFile *) - 0x800efdc8 (4 bytes)
// blr
void ObjectFolderImpl::DeletingResFile(iResFile* file) {
}

// ObjectFolderImpl::GetPlaceholder(void) - 0x800f0884 (60 bytes)
// NON_MATCHING - calls virtual function through vtable at offset 0x78/0x7c with GUID arg
cXObject* ObjectFolderImpl::GetPlaceholder(void) {
    return 0; // TODO: vtable dispatch needed
}

// ObjectFolderImpl::GetTypeAttrBlock(int) - 0x800f1264 (56 bytes)
// Searches vector at +0x660/+0x664 for matching type ID
// NON_MATCHING - loop structure differs
void* ObjectFolderImpl::GetTypeAttrBlock(int typeID) {
    // Iterates through a vector of pointers at offsets 0x660..0x664
    // Each entry: lwz ptr from vector[i]; lwz id from ptr[0]; compare
    return 0;
}

// ObjectFolderImpl::Save(iResFile *) - 0x800f129c (48 bytes)
// NON_MATCHING - calls templated DoStream with 'TATT' tag
void ObjectFolderImpl::Save(iResFile* file) {
    // Calls DoStream-like function at 0x803a736c with tag 0x54415454 ('TATT')
}

// ObjectFolderImpl::Load(iResFile *) - 0x800f12cc (48 bytes)
// NON_MATCHING - calls templated DoStream with 'TATT' tag
void ObjectFolderImpl::Load(iResFile* file) {
    // Calls DoStream-like function at 0x803a73d8 with tag 0x54415454 ('TATT')
}

// findChecksum(unsigned int, ChecksumList &) - 0x800f1628 (52 bytes)
// Walks linked list of checksums searching for match
bool findChecksum(unsigned int checksum, ChecksumList& list) {
    ChecksumList* node = &list;
    // Dereference first pointer
    node = *(ChecksumList**)&list;
    while (node != 0) {
        u32 val = *(u32*)node;
        if (val == checksum) {
            return true;
        }
        node = *(ChecksumList**)((char*)node + 8);
    }
    return false;
}

// ObjectFolderImpl::SuspendObjectFiles(void) - 0x800f1798 (4 bytes)
// blr
void ObjectFolderImpl::SuspendObjectFiles(void) {
}

// ObjectFolderImpl::ResumeObjectFiles(void) - 0x800f179c (4 bytes)
// blr
void ObjectFolderImpl::ResumeObjectFiles(void) {
}

// ObjectFolderImpl::DoCommand(short, int) - 0x800f17a0 (8 bytes)
// li r3,1; blr
int ObjectFolderImpl::DoCommand(short cmd, int param) {
    return 1;
}

// ObjectFolderImpl::IsNamespaceWriteable(unsigned int) - 0x800f2074 (8 bytes)
// li r3,0; blr
int ObjectFolderImpl::IsNamespaceWriteable(unsigned int ns) {
    return 0;
}

// ObjectFolderImpl::IsBehaviorWriteable(unsigned int) - 0x800f207c (8 bytes)
// li r3,0; blr
int ObjectFolderImpl::IsBehaviorWriteable(unsigned int beh) {
    return 0;
}

// ObjectFolderImpl::GetPath(void) - 0x800f29c4 (36 bytes)
// NON_MATCHING - calls StringBuffer c_str at offset +0x550
const char* ObjectFolderImpl::GetPath(void) {
    // Original: addi r3,r3,0x550; bl StringBuffer::c_str
    return 0; // TODO
}

// ObjectFolderImpl::GetBehaviorFinder(void) - 0x800f29e8 (8 bytes)
// addi r3,r3,4; blr
// Returns this+4 (the start of the behavior finder sub-object)
void* ObjectFolderImpl::GetBehaviorFinder(void) {
    return (void*)((char*)this + 4);
}

// ObjectFolderImpl::GetObjectsDatabase(void) - 0x800f29f0 (8 bytes)
// lwz r3, 0x690(r3); blr
void* ObjectFolderImpl::GetObjectsDatabase(void) {
    return *(void**)((char*)this + 0x690);
}

// ObjSelResIDLessThan(ObjSelector *, ObjSelector *) - 0x803a81a0 (32 bytes)
// Compares resource IDs at offset 0x38->0xBC (signed halfword)
// NON_MATCHING - uses mfcr/rlwinm pattern for bool return
bool ObjSelResIDLessThan(ObjSelector* a, ObjSelector* b) {
    // lwz r9,56(r3); lwz r11,56(r4)
    // lha r10,188(r9); lha r0,188(r11)
    // cmpw cr7,r10,r0; mfcr r3; rlwinm r3,r3,29,31,31
    void* aData = *(void**)((char*)a + 0x38);
    void* bData = *(void**)((char*)b + 0x38);
    short aID = *(short*)((char*)aData + 0xBC);
    short bID = *(short*)((char*)bData + 0xBC);
    return aID < bID;
}

// void pop_heap<ObjSelector **, ...>(ObjSelector **, ObjSelector **, ...) - 0x803a6c54 (64 bytes)
// NON_MATCHING - template instantiation, calls __adjust_heap at 0x803a6abc
// Swaps first element with last-1, then sifts down
// template<> void pop_heap<ObjSelector**, bool(*)(ObjSelector*,ObjSelector*)>
// (ObjSelector** first, ObjSelector** last, bool(*comp)(ObjSelector*,ObjSelector*)) {}

// void partial_sort<ObjSelector **, ...>(ObjSelector **, ObjSelector **, ObjSelector **, ...) - 0x803a6d60 (40 bytes)
// NON_MATCHING - template instantiation, calls make_heap+sort_heap at 0x803a6c94
// template<> void partial_sort<ObjSelector**, bool(*)(ObjSelector*,ObjSelector*)>
// (ObjSelector** first, ObjSelector** middle, ObjSelector** last, bool(*comp)(ObjSelector*,ObjSelector*)) {}

// ObjectFolder::~ObjectFolder(void) - 0x803a7dd8 (52 bytes)
// NON_MATCHING - SN generates vtable store + r4&1 delete check
ObjectFolder::~ObjectFolder(void) {
}

// ============================================================================
// SimpleReconObject specializations for objectfolder.obj
// ============================================================================

// SimpleReconObject<ThumbnailLoader>::~SimpleReconObject(void) - 0x803a81c0 (32 bytes)
// NON_MATCHING - GCC generates different dtor chain
template<>
SimpleReconObject<ThumbnailLoader>::~SimpleReconObject(void) {
}

// SimpleReconObject<ObjectSaveTypeTable>::~SimpleReconObject(void) - 0x803a81e0 (32 bytes)
// NON_MATCHING - GCC generates different dtor chain
template<>
SimpleReconObject<ObjectSaveTypeTable>::~SimpleReconObject(void) {
}

// SimpleReconObject<ObjectFolderImpl>::~SimpleReconObject(void) - 0x803a8200 (32 bytes)
// NON_MATCHING - GCC generates different dtor chain
template<>
SimpleReconObject<ObjectFolderImpl>::~SimpleReconObject(void) {
}

// SimpleReconObject<ObjectFolderImpl>::DoStream(ReconBuffer *, int) - 0x803a8220 (56 bytes)
// NON_MATCHING - loads m_impl at +0x04, gets vtable, dispatches through offset 0x138/0x13c
template<>
void SimpleReconObject<ObjectFolderImpl>::DoStream(ReconBuffer* buf, int flags) {
    // Original: loads m_impl->vtable, calls virtual DoStream with this-adjust
}

// SimpleReconObject<ObjectFolderImpl>::GetType(void) - 0x803a8258 (8 bytes)
// lwz r3,8(r3); blr
template<>
short SimpleReconObject<ObjectFolderImpl>::GetType(void) {
    return m_type;
}

// SimpleReconObject<ObjectSaveTypeTable>::DoStream(ReconBuffer *, int) - 0x803a8260 (36 bytes)
// NON_MATCHING - loads m_impl at +0x04, calls DoStream function
template<>
void SimpleReconObject<ObjectSaveTypeTable>::DoStream(ReconBuffer* buf, int flags) {
    // Original: loads m_impl, calls ObjectSaveTypeTable::DoStream
}

// SimpleReconObject<ObjectSaveTypeTable>::GetType(void) - 0x803a8284 (8 bytes)
// lwz r3,8(r3); blr
template<>
short SimpleReconObject<ObjectSaveTypeTable>::GetType(void) {
    return m_type;
}

// SimpleReconObject<ThumbnailLoader>::DoStream(ReconBuffer *, int) - 0x803a828c (36 bytes)
// NON_MATCHING - loads m_impl at +0x04, calls ThumbnailLoader::DoStream
template<>
void SimpleReconObject<ThumbnailLoader>::DoStream(ReconBuffer* buf, int flags) {
    // Original: loads m_impl, calls ThumbnailLoader function at 0x801118c4
}

// SimpleReconObject<ThumbnailLoader>::GetType(void) - 0x803a82b0 (8 bytes)
// lwz r3,8(r3); blr
template<>
short SimpleReconObject<ThumbnailLoader>::GetType(void) {
    return m_type;
}

// ============================================================================
// objectiterator.obj functions
// ============================================================================

// ObjectIterator::ObjectIterator(cXObject *, ObjectIterator::IterateType) - 0x800f2a6c (20 bytes)
// mr r9,r3; stw r4,4(r9); stw r5,8(r9); stw r4,0(r9); blr
ObjectIterator::ObjectIterator(cXObject* start, int type) {
    m_current = start;
    m_start = start;
    m_type = type;
}

// ObjectIterator::operator==(ObjectIterator &) const - 0x800f2a80 (64 bytes)
// Compares m_start pointers, and if both non-null, also compares m_current
bool ObjectIterator::operator==(ObjectIterator& other) const {
    if (m_start != other.m_start) {
        return false;
    }
    if (m_start == 0) {
        return true;
    }
    if (m_current == other.m_current) {
        return true;
    }
    return false;
}

// ============================================================================
// objectmodule.obj functions
// ============================================================================

// ObjectModule::CreateInstance(void) - 0x800f2c54 (40 bytes)
// NON_MATCHING - GCC generates different new+ctor inlining pattern
ObjectModule* ObjectModule::CreateInstance(void) {
    ObjectModuleImpl* impl = new ObjectModuleImpl();
    return impl;
}

// ObjectModule::DestroyInstance(ObjectModule *) - 0x800f2c7c (64 bytes)
// NON_MATCHING - original uses vtable this-adjust + blrl pattern
void ObjectModule::DestroyInstance(ObjectModule* mod) {
    if (mod) {
        delete mod;
    }
}

// MLtraceNull(...) - 0x800f30b8 (4 bytes)
// blr
void MLtraceNull(...) {
}

// DStraceNull(...) - 0x800f3c90 (4 bytes)
// blr
void DStraceNull(...) {
}

// ObjectModuleImpl::ClearKillQueue(void) - 0x800f69b0 (12 bytes)
// lwz r0, 0x2044(r3); stw r0, 0x2048(r3); blr
// Copies kill queue write pointer to read pointer (emptying the queue)
void ObjectModuleImpl::ClearKillQueue(void) {
    u32 val = *(u32*)((char*)this + 0x2044);
    *(u32*)((char*)this + 0x2048) = val;
}

// ObjectModuleImpl::EnqueueObjectDialog(cXObject *, StackElem *, DialogParam *) - 0x800f82c0 (4 bytes)
// blr
void ObjectModuleImpl::EnqueueObjectDialog(cXObject* obj, StackElem* stack, DialogParam* param) {
}

// ObjectModuleImpl::EnqueueObjectDialog(ObjSelector *, DialogParam *) - 0x800f82c4 (4 bytes)
// blr
void ObjectModuleImpl::EnqueueObjectDialog(ObjSelector* sel, DialogParam* param) {
}

// ObjectModuleImpl::SkillAccessed(cXPerson *, int, bool) - 0x800f8550 (4 bytes)
// blr
void ObjectModuleImpl::SkillAccessed(cXPerson* person, int skill, bool flag) {
}

// ObjectModuleImpl::MotiveAccessed(cXPerson *, int, bool) - 0x800f8554 (4 bytes)
// blr
void ObjectModuleImpl::MotiveAccessed(cXPerson* person, int motive, bool flag) {
}

// ObjectModuleImpl::PersonalityAccessed(cXPerson *, int, bool) - 0x800f8558 (4 bytes)
// blr
void ObjectModuleImpl::PersonalityAccessed(cXPerson* person, int personality, bool flag) {
}

// ObjectModuleImpl::RelationshipAccessed(cXObject *, cXObject *, int, bool) - 0x800f855c (4 bytes)
// blr
void ObjectModuleImpl::RelationshipAccessed(cXObject* objA, cXObject* objB, int rel, bool flag) {
}

// ObjectModuleImpl::GetTutorialObject(void) - 0x800f8c54 (24 bytes)
// Checks if tutorial list entry exists at +0x2088, returns object at +0x04
cXObject* ObjectModuleImpl::GetTutorialObject(void) {
    void* entry = *(void**)((char*)this + 0x2088);
    if (entry == 0) return 0;
    return *(cXObject**)((char*)entry + 4);
}

// ObjectModuleImpl::AdvanceSelectedPerson(int) - 0x800f9434 (40 bytes)
// NON_MATCHING - calls external function through r13-relative global
int ObjectModuleImpl::AdvanceSelectedPerson(int direction) {
    // Original: lwz r3,-21432(r13); bl 0x80040cc8; li r3,0
    return 0;
}

// ObjectModuleImpl::GetSelectedPerson(int) - 0x800f945c (36 bytes)
// NON_MATCHING - calls external function through r13-relative global
cXObject* ObjectModuleImpl::GetSelectedPerson(int index) {
    // Original: lwz r3,-21432(r13); bl 0x8004079c
    return 0;
}

// ObjectModuleImpl::SetSimFlag(int, ObjectModule::SimFlag, bool) - 0x800f9578 (56 bytes)
// Loads flags array at +0x1c, indexes by (simIndex-1)*4, sets/clears bit
void ObjectModuleImpl::SetSimFlag(int simIndex, int flag, bool value) {
    int* flags = *(int**)((char*)this + 0x1c);
    int idx = (simIndex - 1);
    int shifted = flag << 16;
    // Clear the flag bit
    flags[idx] &= ~shifted;
    if (value) {
        // If value is true, set the bit
        flags[idx] |= shifted;
    }
}

// ObjectModuleImpl::GetSimFlag(int, ObjectModule::SimFlag) - 0x800f95b0 (40 bytes)
// Loads flags array at +0x1c, indexes by (simIndex-1)*4, tests bit
int ObjectModuleImpl::GetSimFlag(int simIndex, int flag) {
    int* flags = *(int**)((char*)this + 0x1c);
    int idx = (simIndex - 1);
    int shifted = flag << 16;
    if (flags[idx] & shifted) {
        return 1;
    }
    return 0;
}

// ObjectModuleImpl::GetIdleStatus(int) - 0x800f95d8 (24 bytes)
// Loads flags array at +0x1c, indexes by (simIndex-1)*4, extracts low halfword
int ObjectModuleImpl::GetIdleStatus(int simIndex) {
    int* flags = *(int**)((char*)this + 0x1c);
    int idx = (simIndex - 1);
    short* p = (short*)&flags[idx];
    return p[1]; // low halfword (lha at +2)
}

// ObjectModuleImpl::SetIdleStatus(int, int) - 0x800f95f0 (48 bytes)
// Loads flags array at +0x1c, clears low 16 bits, sets new status value
void ObjectModuleImpl::SetIdleStatus(int simIndex, int status) {
    int* flags = *(int**)((char*)this + 0x1c);
    int idx = (simIndex - 1);
    // Clear low 16 bits
    flags[idx] &= 0xFFFF0000;
    // OR in new status (masked to 16 bits)
    status &= 0xFFFF;
    flags[idx] |= status;
}

// ObjectModuleImpl::GetNumObjects(void) - 0x800f9820 (64 bytes)
// Counts non-null entries in 16-element fixed array at +0x20A0, plus vector size at +0x2090
int ObjectModuleImpl::GetNumObjects(void) {
    int count = 0;
    void** fixedArray = (void**)((char*)this + 0x20A0);
    for (int i = 0; i < 16; i++) {
        if (fixedArray[i] != 0) {
            count++;
        }
    }
    // Add vector size from +0x2090/+0x2094
    void* begin = *(void**)((char*)this + 0x2090);
    void* end = *(void**)((char*)this + 0x2094);
    count += ((int)end - (int)begin) / 4;
    return count;
}

// ObjectModuleImpl::GetFolder(void) - 0x800f9928 (8 bytes)
// lwz r3, -21508(r13); blr
ObjectFolder* ObjectModuleImpl::GetFolder(void) {
    return 0; // NON_MATCHING - loads from r13-relative global
}

// ObjectModuleImpl::AddObject(cXObject *, short) - 0x800f9930 (56 bytes)
// NON_MATCHING - calls virtual function through vtable at offset 0x260/0x264
void ObjectModuleImpl::AddObject(cXObject* obj, short id) {
    // Original: loads vtable from this, dispatches through offset 0x260/0x264
}

// ObjectModuleImpl::GetFirst(void) - 0x800f9968 (24 bytes)
// Loads linked list head at +0x2c, returns object at +0x04 if non-null
cXObject* ObjectModuleImpl::GetFirst(void) {
    void* entry = *(void**)((char*)this + 0x2c);
    if (entry == 0) return 0;
    return *(cXObject**)((char*)entry + 4);
}

// ObjectModuleImpl::GetSim(void) - 0x800f9980 (8 bytes)
// lwz r3, -21496(r13); blr
cXObject* ObjectModuleImpl::GetSim(void) {
    return 0; // NON_MATCHING - loads from r13-relative global
}

// ObjectModuleImpl::GetPeople(int) - 0x800f9988 (32 bytes)
// Indexes into vector at +0x2058, returns object at +0x04 if non-null
cXObject* ObjectModuleImpl::GetPeople(int index) {
    void** vec = *(void***)((char*)this + 0x2058);
    void* entry = vec[index];
    if (entry == 0) return 0;
    return *(cXObject**)((char*)entry + 4);
}

// ObjectModuleImpl::GetNumPeople(void) - 0x800f99a8 (20 bytes)
// Returns (end - begin) / 4 for vector at +0x2058/+0x205c
int ObjectModuleImpl::GetNumPeople(void) {
    u32 begin = *(u32*)((char*)this + 0x2058);
    u32 end = *(u32*)((char*)this + 0x205c);
    return (int)(end - begin) / 4;
}

// ObjectModuleImpl::GetPortal(int) - 0x800f99bc (16 bytes)
// Indexes into vector at +0x2068
cXObject* ObjectModuleImpl::GetPortal(int index) {
    void** vec = *(void***)((char*)this + 0x2068);
    return (cXObject*)vec[index];
}

// ObjectModuleImpl::GetNumPortals(void) - 0x800f99cc (20 bytes)
// Returns (end - begin) / 4 for vector at +0x2068/+0x206c
int ObjectModuleImpl::GetNumPortals(void) {
    u32 begin = *(u32*)((char*)this + 0x2068);
    u32 end = *(u32*)((char*)this + 0x206c);
    return (int)(end - begin) / 4;
}

// ObjectModuleImpl::GetGlobalRoutingSlot(int) - 0x800f99e0 (16 bytes)
// Indexes into array at +0x2078 with stride 60 (0x3c)
cXObject* ObjectModuleImpl::GetGlobalRoutingSlot(int index) {
    char* base = *(char**)((char*)this + 0x2078);
    return (cXObject*)(base + index * 60);
}

// ObjectModuleImpl::GetNumGlobalRoutingSlots(void) - 0x800f99f0 (32 bytes)
// Returns (end - begin) / 60 for array at +0x2078/+0x207c
// Uses magic number multiply for division by 60
int ObjectModuleImpl::GetNumGlobalRoutingSlots(void) {
    u32 begin = *(u32*)((char*)this + 0x2078);
    u32 end = *(u32*)((char*)this + 0x207c);
    return (int)(end - begin) / 60;
}

// ObjectModuleImpl::IsBuyAndBuildDisabled(void) - 0x800f9a10 (36 bytes)
// Checks if disabled vector at +0x2034/+0x2038 has any entries
int ObjectModuleImpl::IsBuyAndBuildDisabled(void) {
    u32 begin = *(u32*)((char*)this + 0x2034);
    u32 end = *(u32*)((char*)this + 0x2038);
    int size = (int)(end - begin) / 4;
    if (size != 0) {
        return 1;
    }
    return 0;
}

// ObjectModule::~ObjectModule(void) - 0x803a8608 (52 bytes)
// NON_MATCHING - SN generates vtable store + r4&1 delete check
ObjectModule::~ObjectModule(void) {
}

// SimpleReconObject<ObjectModuleImpl>::~SimpleReconObject(void) - 0x803a863c (32 bytes)
// NON_MATCHING - GCC generates different dtor chain
template<>
SimpleReconObject<ObjectModuleImpl>::~SimpleReconObject(void) {
}

// SimpleReconObject<ObjectModuleImpl>::DoStream(ReconBuffer *, int) - 0x803a865c (56 bytes)
// NON_MATCHING - loads m_impl at +0x04, gets vtable, dispatches through offset 0x1d0/0x1d4
template<>
void SimpleReconObject<ObjectModuleImpl>::DoStream(ReconBuffer* buf, int flags) {
    // Original: loads m_impl->vtable, calls virtual DoStream with this-adjust
}

// SimpleReconObject<ObjectModuleImpl>::GetType(void) - 0x803a8694 (8 bytes)
// lwz r3,8(r3); blr
template<>
short SimpleReconObject<ObjectModuleImpl>::GetType(void) {
    return m_type;
}

// ============================================================================
// objfntable.obj functions
// ============================================================================

// ObjFnTableQuickData::CreateInstance(void) - 0x8010fe60 (40 bytes)
// NON_MATCHING - allocates 24 bytes, calls constructor
ObjFnTableQuickData* ObjFnTableQuickData::CreateInstance(void) {
    ObjFnTableQuickData* data = (ObjFnTableQuickData*)operator new(24);
    // calls constructor at 0x8010ff18
    return data;
}

// ObjFnTable::CreateInstance(void) - 0x8010fe88 (40 bytes)
// NON_MATCHING - allocates 24 bytes, calls constructor
ObjFnTable* ObjFnTable::CreateInstance(void) {
    ObjFnTable* table = (ObjFnTable*)operator new(24);
    // calls constructor at 0x8010ff18
    return table;
}

// ObjFnTable::CreateInstance(ObjectDataID &) - 0x8010feb0 (40 bytes)
// NON_MATCHING - allocates 24 bytes, calls constructor
ObjFnTable* ObjFnTable::CreateInstance(ObjectDataID& dataID) {
    ObjFnTable* table = (ObjFnTable*)operator new(24);
    // calls constructor at 0x8010ff18
    return table;
}

// ObjFnTable::DestroyInstance(ObjFnTable *) - 0x8010fed8 (64 bytes)
// NON_MATCHING - original uses vtable this-adjust + blrl at offset 0x60/0x64
void ObjFnTable::DestroyInstance(ObjFnTable* table) {
    if (table) {
        delete table;
    }
}

// ObjFnTableQuickData::GetDataSourceType(void) const - 0x8010ffcc (8 bytes)
// li r3,1; blr
int ObjFnTableQuickData::GetDataSourceType(void) const {
    return 1;
}

// ObjFnTableQuickData::SetTreeID(ObjEntryPoint, short) - 0x8011005c (4 bytes)
// blr
void ObjFnTableQuickData::SetTreeID(ObjEntryPoint entry, short id) {
}

// ObjFnTableQuickData::SetCheckTreeID(ObjEntryPoint, short) - 0x80110060 (4 bytes)
// blr
void ObjFnTableQuickData::SetCheckTreeID(ObjEntryPoint entry, short id) {
}

// ObjFnTableQuickData::GetDataID(void) const - 0x801101c0 (52 bytes)
// NON_MATCHING - loads ObjectDataID and calls copy function
ObjFnTableQuickData* ObjFnTableQuickData::GetDataID(void) const {
    return (ObjFnTableQuickData*)this; // NON_MATCHING
}

// ObjFnTableQuickData::SaveDataByID(ObjectDataID &) - 0x80110238 (8 bytes)
// li r3,0; blr
int ObjFnTableQuickData::SaveDataByID(ObjectDataID& dataID) {
    return 0;
}

// ObjFnTableQuickData::GetResourceName(StringBuffer &) const - 0x80110240 (8 bytes)
// li r3,0; blr
int ObjFnTableQuickData::GetResourceName(StringBuffer& name) const {
    return 0;
}

// ObjFnTableQuickData::SetResourceName(StringBuffer &) - 0x80110248 (8 bytes)
// li r3,0; blr
int ObjFnTableQuickData::SetResourceName(StringBuffer& name) {
    return 0;
}

// ObjFnTableQuickData::AddRef(void) - 0x801102c0 (20 bytes)
// mr r9,r3; lwz r3,20(r9); addi r3,r3,1; stw r3,20(r9); blr
int ObjFnTableQuickData::AddRef(void) {
    m_refCount++;
    return m_refCount;
}

// ObjFnTableQuickData::LoadFromIndex(unsigned int, int) - 0x80110330 (8 bytes)
// li r3,0; blr
int ObjFnTableQuickData::LoadFromIndex(unsigned int index, int param) {
    return 0;
}

// ObjFnTableQuickData::LoadOnlyNameAndIDFromIndex(unsigned int, int) - 0x80110338 (8 bytes)
// li r3,0; blr
int ObjFnTableQuickData::LoadOnlyNameAndIDFromIndex(unsigned int index, int param) {
    return 0;
}

// ObjFnTable::~ObjFnTable(void) - 0x803a870c (52 bytes)
// NON_MATCHING - SN generates vtable store + r4&1 delete check
ObjFnTable::~ObjFnTable(void) {
}

// ============================================================================
// objtestsim.obj functions
// ============================================================================

// __tcf_0 (objtestsim.obj) - 0x80112020 (40 bytes)
// NON_MATCHING - destructor for static ModEntry object
// Original: addi r3,r13,-24148; li r4,2; bl 0x800a1d70
void __tcf_0(void) {
    // Destroys static object at r13-24148 with mode 2
}

// ObjTestSim::ObjTestSim(cXPerson *) - 0x80112048 (24 bytes)
// mr r9,r3; li r0,0; stw r4,0(r9); stw r0,24(r9); stw r0,4(r9); blr
ObjTestSim::ObjTestSim(cXPerson* person) {
    m_person = person;
    m_menuObject = 0;
    m_objectPtr = 0;
}

// ObjTestSim::SetupInteractionColors(Interaction *, short) - 0x801126e0 (60 bytes)
// NON_MATCHING - complex vtable dispatch pattern
void ObjTestSim::SetupInteractionColors(Interaction* interaction, short entryIndex) {
    // Accesses interaction vtable to get color data
    // Too complex for simple decomp without full class layout
}

// ObjTestSim::IsMenuInProgress(void) - 0x80112c40 (48 bytes)
// NON_MATCHING - checks m_menuObject at +0x18 and its contents
bool ObjTestSim::IsMenuInProgress(void) {
    if (m_menuObject == 0) return false;
    // Loads vtable from menuObject->something and checks
    return false;
}

// InteractionList::InteractionList(void) - 0x80113018 (20 bytes)
// Zeroes out 5 fields
InteractionList::InteractionList(void) {
    m_head = 0;
    m_tail = 0;
    m_size = 0;
    m_pad0c = 0;
    m_pad10 = 0;
}

// InteractionList::~InteractionList(void) - 0x8011302c (64 bytes)
// NON_MATCHING - destructor with loop to free nodes
InteractionList::~InteractionList(void) {
    // Frees all nodes in the list
}

// InteractionList::size(void) const - 0x8011306c (40 bytes)
// NON_MATCHING - register allocation may differ
int InteractionList::size(void) const {
    // Original iterates through list counting nodes
    // This is a linked list, not a vector
    return m_size;
}

// InteractionList::increment(InteractionList::iterator &) - 0x801132f0 (24 bytes)
// Advances iterator to next node
void InteractionList::increment(int& it) {
    // NON_MATCHING - advances node pointer
    // Original likely does: it.m_node = it.m_node->next
}

// InteractionList::iterator::operator++(void) - 0x80113308 (52 bytes)
// NON_MATCHING - calls increment, returns iterator
int& InteractionList::iterator::operator++(void) {
    // Original calls InteractionList::increment on this
    return *this;
}

// global constructors keyed to ObjTestSim::sCheckTreeModEntry - 0x80113390 (44 bytes)
// NON_MATCHING - initializes static ModEntry data
void _GLOBAL__I_sCheckTreeModEntry(void) {
    // Constructs the static sCheckTreeModEntry object
}

// global destructors keyed to ObjTestSim::sCheckTreeModEntry - 0x801133bc (44 bytes)
// NON_MATCHING - destroys static ModEntry data
void _GLOBAL__D_sCheckTreeModEntry(void) {
    // Destroys the static sCheckTreeModEntry object
}

// ============================================================================
// stubobject.obj - StubObject::GenerateHash(void) - 0x80145d58 (72 bytes)
// NON_MATCHING - uses random number + hash generation
// ============================================================================
int StubObject::GenerateHash(void) {
    // Original:
    // Sets up stack frame, calls two functions to get random values,
    // XORs them together for a hash
    // bl 0x8007d6c0 (seed/init)
    // bl 0x8007d79c (get random)
    // bl 0x802432b0 (get time-based value)
    // XOR results together
    return 0; // NON_MATCHING
}
