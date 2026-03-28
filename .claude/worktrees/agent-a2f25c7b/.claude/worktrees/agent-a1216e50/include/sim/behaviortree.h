#ifndef BEHAVIORTREE_H
#define BEHAVIORTREE_H

#include "types.h"

// Forward declarations
class StringBuffer;
class BehaviorNode;

// ============================================================================
// ObjectDataID - Identifier for object data resources
// Size: 8 bytes (at offset +0x58 in ObjectDataBehaviorTree, constructed with 3 args)
// ============================================================================
struct ObjectDataID {
    int m_field0;  // +0x00
    int m_field4;  // +0x04
};

// ============================================================================
// BehaviorTreeHeader - Raw header data for a behavior tree
// Pointed to by ObjectDataBehaviorTree::m_pHeader (+0x54)
//
// Layout:
//   +0x00: structVersion (short)
//   +0x02: numNodes (short)
//   +0x04: type (u8)
//   +0x05: numParams (u8)
//   +0x06: numLocals (u8)
//   +0x07: padding
//   +0x08: treeVersionInt (int) - SetTreeVersion stores full int here
//   +0x0B: treeVersion (u8) - GetTreeVersion reads byte here
//   +0x0C: nodes[] - array of 12-byte node entries
// ============================================================================
struct BehaviorTreeHeader {
    short m_structVersion;   // +0x00
    short m_numNodes;        // +0x02
    u8 m_type;               // +0x04
    u8 m_numParams;          // +0x05
    u8 m_numLocals;          // +0x06
    u8 m_pad07;              // +0x07
    int m_treeVersionData;   // +0x08 (byte at +0x0B is treeVersion for GetTreeVersion)
    // Nodes follow at +0x0C, each 12 bytes
};

// ============================================================================
// ObjectDataBehaviorTree - Base class for behavior tree data
//
// Object file: behaviortree.obj
// Vtable at 0x804658C0 (size 0x78)
//
// Layout (0x60 bytes):
//   +0x00: vtable pointer
//   +0x04: m_resID (short)
//   +0x06: padding
//   +0x08: m_field08 (int, set to 0 in ctor)
//   +0x0C: m_name (StringBuffer, initialized with buf at +0x14, size 64)
//   +0x14: m_nameBuf[64] (char[64], inline buffer for StringBuffer)
//   +0x54: m_pHeader (BehaviorTreeHeader*)
//   +0x58: m_dataID (ObjectDataID, 8 bytes)
// ============================================================================
class ObjectDataBehaviorTree {
public:
    ObjectDataBehaviorTree();
    ObjectDataBehaviorTree(ObjectDataBehaviorTree& other);
    virtual ~ObjectDataBehaviorTree();

    // Virtual methods (from vtable)
    virtual int QueryInterface(unsigned int iid, void** ppv);
    virtual int AddRef();
    virtual int Release();
    virtual void GetDataID(ObjectDataID& outID) const;
    virtual int LoadFromDataID(ObjectDataID& id);
    virtual int LoadFromIndex(unsigned int index, int scope);
    virtual int SaveDataByID(ObjectDataID& id);
    virtual int GetResourceName(StringBuffer& buf) const;
    virtual int SetResourceName(StringBuffer& buf);
    virtual int GetDataSourceType() const;
    virtual int LoadOnlyNameAndIDFromIndex(unsigned int index, int scope);
    virtual int GetFromDataID(ObjectDataID& id);

    // Non-virtual methods
    short GetStructVersion() const;
    short GetNumNodes() const;
    u8 GetType() const;
    void SetType(u8 type);
    u8 GetNumParams() const;
    void SetNumParams(u8 params);
    u8 GetNumLocals() const;
    void SetNumLocals(u8 locals);
    u8 GetTreeVersion() const;
    void SetTreeVersion(u8 version);
    BehaviorNode* GetNode(unsigned int index) const;
    short GetResID() const;
    void SetResID(short id);

protected:
    short m_resID;               // +0x04
    short m_pad06;               // +0x06
    int m_field08;               // +0x08
    char m_name[0x48];           // +0x0C (StringBuffer with inline 64-byte buffer)
    BehaviorTreeHeader* m_pHeader; // +0x54
    ObjectDataID m_dataID;       // +0x58
};

// ============================================================================
// ResourceBehaviorTree - Behavior tree loaded from resource files
//
// Object file: behaviortree.obj
// Vtable at 0x80465848 (size 0x78)
//
// Layout extends ObjectDataBehaviorTree:
//   +0x60: m_field60 (int, zeroed in ctor)
//   +0x64: m_refCount (int)
// ============================================================================
class ResourceBehaviorTree : public ObjectDataBehaviorTree {
public:
    ResourceBehaviorTree();
    virtual ~ResourceBehaviorTree();

    // Virtual overrides
    virtual int QueryInterface(unsigned int iid, void** ppv);
    virtual int AddRef();
    virtual int Release();
    virtual int LoadFromDataID(ObjectDataID& id);
    virtual int LoadFromIndex(unsigned int index, int scope);
    virtual int SaveDataByID(ObjectDataID& id);
    virtual int GetDataSourceType() const;
    virtual int LoadOnlyNameAndIDFromIndex(unsigned int index, int scope);
    virtual int GetFromDataID(ObjectDataID& id);

    // Memory management
    void* operator new(unsigned int size);
    void operator delete(void* ptr);

private:
    int m_field60;    // +0x60
    int m_refCount;   // +0x64
};

// ============================================================================
// IFFBehaviorTree - Behavior tree loaded from IFF files
//
// Object file: behaviortree.obj
// Vtable at 0x804657D0 (size 0x78)
//
// Layout extends ObjectDataBehaviorTree:
//   +0x60: m_refCount (int)
// ============================================================================
class IFFBehaviorTree : public ObjectDataBehaviorTree {
public:
    IFFBehaviorTree();
    IFFBehaviorTree(int param);
    virtual ~IFFBehaviorTree();

    // Virtual overrides
    virtual int QueryInterface(unsigned int iid, void** ppv);
    virtual int AddRef();
    virtual int Release();
    virtual int LoadFromDataID(ObjectDataID& id);
    virtual int LoadFromIndex(unsigned int index, int scope);
    virtual int SaveDataByID(ObjectDataID& id);
    virtual int GetDataSourceType() const;
    virtual int LoadOnlyNameAndIDFromIndex(unsigned int index, int scope);
    virtual int GetFromDataID(ObjectDataID& id);

private:
    int m_refCount;   // +0x60
};

// Pool for ResourceBehaviorTree allocation
// g_poolResourceBehaviorTree at 0x804874C0
extern char g_poolResourceBehaviorTree[];

#endif // BEHAVIORTREE_H
