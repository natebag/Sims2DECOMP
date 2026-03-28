#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "types.h"

// Forward declarations
class ObjSelector;
class ObjectDataBehaviorTree;
class ObjectDataBehaviorConstants;
class StringBuffer;
class BehaviorNode;

// ============================================================================
// BehaviorNodeParam - Parameter for behavior nodes
// Size: 8 bytes
// ============================================================================
struct BehaviorNodeParam {
    int m_field0;   // +0x00
    int m_field4;   // +0x04
};

// ============================================================================
// BehPrintParams - Parameters for behavior tree printing/debug
// ============================================================================
class BehPrintParams {
public:
    void SetFilename(char* filename);
    // Internal data...
};

// ============================================================================
// Language - Base class for behavior tree language/execution
//
// Object file: behavior.obj
// Vtable at 0x8045E8D0 (size 0x48)
//
// Virtual methods (from vtable analysis):
//   +0x0C: pure virtual (stub 80249e14)
//   +0x14: pure virtual
//   +0x1C: pure virtual
//   +0x24: pure virtual
//   +0x2C: pure virtual
//   +0x34: IsSingleExit (returns 0)
//   +0x3C: GetSwizzler (returns 0)
// ============================================================================
class Language {
public:
    virtual ~Language();

    // Vtable virtuals
    virtual int QueryInterface(unsigned int iid, void** ppv) = 0;
    virtual int AddRef() = 0;
    virtual int Release() = 0;
    virtual int Unknown_0x24() = 0;
    virtual int CountPrimitives() = 0;
    virtual bool IsSingleExit(BehaviorNode* node);
    virtual void* GetSwizzler();

    // No data members beyond vtable
};

// ============================================================================
// Behavior - Manages behavior trees for objects
//
// Object file: behavior.obj
// Vtable at 0x8045E878 (size 0x58)
//
// Layout:
//   +0x00: vtable pointer
//   +0x04: m_pOwner (ObjSelector*)
//   +0x08: m_pLanguage (Language*)
//
// Static data:
//   Behavior::s_cachedTrees at 0x80485DB0 (0x30 bytes)
//   Behavior::s_cacheTreesRefCount at 0x804FDBA4
//
// Vtable entries (from 0x8045E878):
//   +0x0C: pure virtual (80249e14)
//   +0x14: pure virtual
//   +0x1C: pure virtual
//   +0x24: ~Behavior (800AB314)
//   +0x2C: Init (800AC650)
//   +0x34: CountTrees/GetNode (800AB968)
//   +0x3C: pure virtual
//   +0x44: pure virtual
//   +0x4C: pure virtual
// ============================================================================
class Behavior {
public:
    Behavior();
    virtual ~Behavior();

    // Virtual methods
    virtual int QueryInterface(unsigned int iid, void** ppv) = 0;
    virtual int AddRef() = 0;
    virtual int Release() = 0;
    virtual void Init(Language* lang, ObjSelector* owner);
    virtual int CountTrees(short scope);
    virtual int GetTreeByIndex(int index, short scope, ObjectDataBehaviorTree** ppTree) = 0;
    virtual int GetTreeIDByName(char* name) = 0;

    // Non-virtual methods
    int GetNamespaceID();
    int GetSemiGlobalNamespaceID();
    int GetGlobNamespaceID();
    void GetNodeText(short param1, BehaviorNode* node, StringBuffer& buf);
    int CountPrimitives();
    int GetNode(short param1, short param2, BehaviorNode* node);
    int GetNodeRef(short param1, short param2, BehaviorNode** ppNode);
    int IsNodeReachable(short param, int flag);
    int GetNodeText(short param1, short param2, StringBuffer& buf);
    int GetResFileID(short scope);
    static int GetBaseID(short scope);
    static int GetMaxID(short scope);
    int GetTreeClass(short scope);
    int GetClassName(short scope, StringBuffer& buf);
    int IsSingleExit(short param1, short param2);
    int GetCumulativeTreeVersion(short scope);
    int GetTree(short id, ObjectDataBehaviorTree** ppTree, bool flag);
    short GetTreeIDByNameFast(char* name);
    int GetTreeName(short id, StringBuffer& buf);
    int GetConstants(short scope, ObjectDataBehaviorConstants** ppConst);
    int GetResFileIDByClass(short scope);
    static bool IsDefaultParam(BehaviorNodeParam* param);
    static void SetDefaultParam(BehaviorNodeParam* param);
    ObjSelector* GetOwner();
    Language* GetLanguage();
    int CountNodes(short scope);

    // Static members
    static int s_cacheTreesRefCount;
    // s_cachedTrees is a more complex structure at 0x80485DB0

private:
    ObjSelector* m_pOwner;     // +0x04
    Language* m_pLanguage;     // +0x08
};

// ============================================================================
// ResourceBehavior - Behavior loaded from resource files
//
// Object file: behavior.obj
// Vtable at 0x8045E820 (size 0x58)
//
// Layout:
//   +0x00-0x08: Behavior base
//   +0x0C-0x1B: additional data
//   +0x1C: m_refCount (int)
// ============================================================================
class ResourceBehavior : public Behavior {
public:
    ResourceBehavior();
    virtual ~ResourceBehavior();

    // Virtual overrides
    virtual int QueryInterface(unsigned int iid, void** ppv);
    virtual int AddRef();
    virtual int Release();
    virtual void Init(Language* lang, ObjSelector* owner);
    virtual int CountTrees(short scope);
    virtual int GetTreeByIndex(int index, short scope, ObjectDataBehaviorTree** ppTree);
    virtual int GetTreeIDByName(char* name);

private:
    char m_data[0x10];    // +0x0C
    int m_refCount;       // +0x1C
};

// ============================================================================
// IFFBehavior - Behavior loaded from IFF files
//
// Object file: behavior.obj
// Vtable at 0x8045E7C8 (size 0x58)
//
// Layout:
//   +0x00-0x08: Behavior base
//   +0x0C: additional data
//   +0x10: m_refCount (int)
// ============================================================================
class IFFBehavior : public Behavior {
public:
    IFFBehavior();
    virtual ~IFFBehavior();

    // Virtual overrides
    virtual int QueryInterface(unsigned int iid, void** ppv);
    virtual int AddRef();
    virtual int Release();
    virtual int CountTrees(short scope);
    virtual int GetTreeByIndex(int index, short scope, ObjectDataBehaviorTree** ppTree);
    virtual int GetTreeIDByName(char* name);

private:
    char m_data[0x04];    // +0x0C
    int m_refCount;       // +0x10
};

#endif // BEHAVIOR_H
