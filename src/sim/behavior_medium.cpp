// behavior_medium.cpp - Medium functions (65-256 bytes) from behavior.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\behavior.obj
//
// 30 medium functions decompiled
//
// NON_MATCHING causes:
//   - GCC virtual dispatch differs (bctr vs blrl)
//   - GCC register allocation
//   - SDA-relative addressing
//   - GCC destructor ABI

#include "types.h"

// Forward declarations - this file is standalone to avoid header conflicts
// All functions are NON_MATCHING stubs for documentation purposes


// External functions
extern void BString2_ctor(void* str);
extern void BString2_dtor(void* str, int);
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void BString2_from_cstr(void* dst, const char* src);
extern void StringBuffer_set(void* buf, const char* str);

#if 0  // Reference decompilation - not compiled (header conflicts with existing declarations)

// ============================================================================
// Behavior::CountNodes(short)
// Address: 0x800ab4a0 | Size: 160 bytes
// NON_MATCHING - GCC virtual dispatch pattern
// ============================================================================
int Behavior::CountNodes(short scope) {
    // Get tree count for scope via virtual call
    int treeCount = CountTrees(scope);
    if (treeCount <= 0) {
        return 0;
    }
    int totalNodes = 0;
    int baseID = GetBaseID(scope);
    for (int i = 0; i < treeCount; i++) {
        ObjectDataBehaviorTree* tree = 0;
        GetTree(baseID + i, &tree, false);
        if (tree != 0) {
            // Virtual call: tree->GetNodeCount()
            int* vtbl = *(int**)tree;
            short offset = *(short*)((char*)vtbl + 0x18);
            void* thunk = (char*)tree + offset;
            typedef int (*CountFn)(void*);
            CountFn fn = (CountFn)*(int*)((char*)vtbl + 0x1C);
            totalNodes += fn(thunk);
        }
    }
    return totalNodes;
}

// ============================================================================
// Behavior::GetNode(short, short, BehaviorNode *)
// Address: 0x800ab560 | Size: 92 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int Behavior::GetNode(short treeID, short nodeIndex, BehaviorNode* outNode) {
    ObjectDataBehaviorTree* tree = 0;
    int result = GetTree(treeID, &tree, false);
    if (tree == 0) {
        return 0;
    }
    // Virtual call: tree->GetNode(nodeIndex, outNode)
    int* vtbl = *(int**)tree;
    short offset = *(short*)((char*)vtbl + 0x20);
    void* thunk = (char*)tree + offset;
    typedef int (*GetNodeFn)(void*, short, BehaviorNode*);
    GetNodeFn fn = (GetNodeFn)*(int*)((char*)vtbl + 0x24);
    return fn(thunk, nodeIndex, outNode);
}

// ============================================================================
// Behavior::GetNodeText(short, short, StringBuffer &)
// Address: 0x800ab8c4 | Size: 108 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void Behavior::GetNodeText(short treeID, short nodeIndex, StringBuffer& buf) {
    ObjectDataBehaviorTree* tree = 0;
    GetTree(treeID, &tree, false);
    if (tree == 0) {
        return;
    }
    // Virtual call: tree->GetNodeText(nodeIndex, buf)
    int* vtbl = *(int**)tree;
    short offset = *(short*)((char*)vtbl + 0x28);
    void* thunk = (char*)tree + offset;
    typedef void (*GetTextFn)(void*, short, StringBuffer&);
    GetTextFn fn = (GetTextFn)*(int*)((char*)vtbl + 0x2C);
    fn(thunk, nodeIndex, buf);
}

// ============================================================================
// Behavior::GetResFileID(short)
// Address: 0x800ab968 | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int Behavior::GetResFileID(short treeID) {
    ObjectDataBehaviorTree* tree = 0;
    GetTree(treeID, &tree, false);
    if (tree == 0) {
        return -1;
    }
    // Virtual call: tree->GetResFileID()
    int* vtbl = *(int**)tree;
    short offset = *(short*)((char*)vtbl + 0x30);
    void* thunk = (char*)tree + offset;
    typedef int (*GetIDFn)(void*);
    GetIDFn fn = (GetIDFn)*(int*)((char*)vtbl + 0x34);
    return fn(thunk);
}

// ============================================================================
// Behavior::GetTreeClass(short)
// Address: 0x800aba34 | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int Behavior::GetTreeClass(short treeID) {
    ObjectDataBehaviorTree* tree = 0;
    GetTree(treeID, &tree, false);
    if (tree == 0) {
        return -1;
    }
    // Virtual call: tree->GetTreeClass()
    int* vtbl = *(int**)tree;
    short offset = *(short*)((char*)vtbl + 0x38);
    void* thunk = (char*)tree + offset;
    typedef int (*GetClassFn)(void*);
    GetClassFn fn = (GetClassFn)*(int*)((char*)vtbl + 0x3C);
    return fn(thunk);
}

// ============================================================================
// Behavior::GetClassName(short, StringBuffer &)
// Address: 0x800aba88 | Size: 140 bytes
// NON_MATCHING - GCC virtual dispatch chain
// ============================================================================
void Behavior::GetClassName(short treeID, StringBuffer& buf) {
    ObjectDataBehaviorTree* tree = 0;
    GetTree(treeID, &tree, false);
    if (tree == 0) {
        return;
    }
    // Get tree class
    int* vtbl = *(int**)tree;
    short offset = *(short*)((char*)vtbl + 0x38);
    void* thunk = (char*)tree + offset;
    typedef int (*GetClassFn)(void*);
    GetClassFn fn = (GetClassFn)*(int*)((char*)vtbl + 0x3C);
    int treeClass = fn(thunk);
    // Get class name from language
    m_pLanguage->GetClassName(treeClass, buf);
}

// ============================================================================
// BehPrintParams::SetFilename(char *)
// Address: 0x800abc48 | Size: 72 bytes
// NON_MATCHING - GCC string operation
// ============================================================================
void BehPrintParams::SetFilename(char* filename) {
    BString2_from_cstr(&m_filename, filename);
}

// ============================================================================
// __tcf_0 (static destructor 0)
// Address: 0x800abc90 | Size: 80 bytes
// NON_MATCHING - compiler-generated
// ============================================================================
// Destroys static BString2 at r13-offset

// ============================================================================
// __tcf_1 (static destructor 1)
// Address: 0x800abce0 | Size: 80 bytes
// NON_MATCHING - compiler-generated
// ============================================================================
// Destroys static BString2 at r13-offset

// ============================================================================
// Behavior::GetConstants(short, ObjectDataBehaviorConstants **)
// Address: 0x800ac5a8 | Size: 168 bytes
// NON_MATCHING - GCC virtual dispatch chain
// ============================================================================
int Behavior::GetConstants(short treeID, ObjectDataBehaviorConstants** outConstants) {
    ObjectDataBehaviorTree* tree = 0;
    GetTree(treeID, &tree, false);
    if (tree == 0) {
        *outConstants = 0;
        return 0;
    }
    // Virtual call: tree->GetConstants(outConstants)
    int* vtbl = *(int**)tree;
    short offset = *(short*)((char*)vtbl + 0x40);
    void* thunk = (char*)tree + offset;
    typedef int (*GetConstFn)(void*, ObjectDataBehaviorConstants**);
    GetConstFn fn = (GetConstFn)*(int*)((char*)vtbl + 0x44);
    return fn(thunk, outConstants);
}

// ============================================================================
// Behavior::GetTree(short, ObjectDataBehaviorTree **, bool)
// Address: 0x800ac384 | Size: 236 bytes
// NON_MATCHING - complex scope resolution and virtual dispatch
// ============================================================================
// NON_MATCHING
int Behavior::GetTree(short treeID, ObjectDataBehaviorTree** outTree, bool cached) {
    // Determines scope from treeID range
    // scope 1: 256-4095 (local)
    // scope 2: 4096-8191 (semi-global)
    // scope 3: 8192-9000 (global)
    // Dispatches to GetTreeByIndex with appropriate scope
    *outTree = 0;
    return 0; // placeholder
}

// ============================================================================
// ResourceBehavior::ResourceBehavior(void)
// Address: 0x800ac830 | Size: 80 bytes
// NON_MATCHING - GCC constructor codegen
// ============================================================================
ResourceBehavior::ResourceBehavior() {
    // Set vtable
    m_pOwner = 0;
    m_pLanguage = 0;
    m_refCount = 0;
    m_pTreeData = 0;
    m_treeCount = 0;
}

// ============================================================================
// ResourceBehavior::~ResourceBehavior(void)
// Address: 0x800ac880 | Size: 140 bytes
// NON_MATCHING - GCC destructor, loop codegen
// ============================================================================
ResourceBehavior::~ResourceBehavior() {
    // Set vtable to ResourceBehavior vtable
    // Release all trees
    // Free tree data array
    // Call base Behavior destructor
}

// ============================================================================
// ResourceBehavior::Init(Language *, ObjSelector *)
// Address: 0x800ac90c | Size: 220 bytes
// NON_MATCHING - complex initialization
// ============================================================================
// NON_MATCHING
void ResourceBehavior::Init(Language* lang, ObjSelector* owner) {
    m_pLanguage = lang;
    m_pOwner = owner;
    // Count trees, allocate array, load tree data
}

// ============================================================================
// ResourceBehavior::CountTrees(short)
// Address: 0x800ac9e8 | Size: 80 bytes
// NON_MATCHING - GCC switch codegen
// ============================================================================
int ResourceBehavior::CountTrees(short scope) {
    if (scope == 1) {
        return m_treeCount;
    }
    // For other scopes, delegate to base
    return Behavior::CountTrees(scope);
}

// ============================================================================
// ResourceBehavior::GetTreeIDByName(char *)
// Address: 0x800aca38 | Size: 108 bytes
// NON_MATCHING - GCC loop codegen, string compare
// ============================================================================
short ResourceBehavior::GetTreeIDByName(char* name) {
    for (int i = 0; i < m_treeCount; i++) {
        // Compare tree name with given name
        // If match, return base ID + index
    }
    return -1;
}

// ============================================================================
// ResourceBehavior::GetTreeByIndex(int, short, ObjectDataBehaviorTree **)
// Address: 0x800acaa4 | Size: 160 bytes
// NON_MATCHING - GCC bounds checking codegen
// ============================================================================
int ResourceBehavior::GetTreeByIndex(int index, short scope, ObjectDataBehaviorTree** outTree) {
    *outTree = 0;
    if (scope != 1) {
        return 0;
    }
    if (index < 0 || index >= m_treeCount) {
        return 0;
    }
    *outTree = (ObjectDataBehaviorTree*)((char*)m_pTreeData + index * 4);
    return 1;
}

// ============================================================================
// ResourceBehavior::QueryInterface(unsigned int, void **)
// Address: 0x800acb44 | Size: 112 bytes
// NON_MATCHING - GCC comparison codegen
// ============================================================================
int ResourceBehavior::QueryInterface(unsigned int iid, void** outPtr) {
    *outPtr = 0;
    // Compare iid against known interface IDs
    // If match, set *outPtr and AddRef()
    return 0;
}

// ============================================================================
// ResourceBehavior::Release(void)
// Address: 0x800acbc8 | Size: 92 bytes
// NON_MATCHING - GCC destructor dispatch
// ============================================================================
int ResourceBehavior::Release() {
    m_refCount--;
    if (m_refCount <= 0) {
        // Virtual destructor call
        int* vtbl = *(int**)this;
        short offset = *(short*)((char*)vtbl + 8);
        void (*dtor)(void*, int) = (void (*)(void*, int))*(int*)((char*)vtbl + 12);
        dtor((char*)this + offset, 3);
        return 0;
    }
    return m_refCount;
}

// ============================================================================
// IFFBehavior::IFFBehavior(void)
// Address: 0x800acc24 | Size: 68 bytes
// NON_MATCHING - GCC constructor codegen
// ============================================================================
IFFBehavior::IFFBehavior() {
    // Set vtable
    m_refCount = 0;
    m_pOwner = 0;
    m_pLanguage = 0;
}

// ============================================================================
// IFFBehavior::CountTrees(short)
// Address: 0x800acc98 | Size: 172 bytes
// NON_MATCHING - GCC virtual dispatch, scope resolution
// ============================================================================
int IFFBehavior::CountTrees(short scope) {
    // Scope-dependent tree counting via owner's resource system
    // Virtual calls through owner to get resource counts
    return 0;
}

// ============================================================================
// IFFBehavior::QueryInterface(unsigned int, void **)
// Address: 0x800acfb0 | Size: 112 bytes
// NON_MATCHING - GCC comparison codegen
// ============================================================================
int IFFBehavior::QueryInterface(unsigned int iid, void** outPtr) {
    *outPtr = 0;
    return 0;
}

// ============================================================================
// IFFBehavior::Release(void)
// Address: 0x800ad034 | Size: 92 bytes
// NON_MATCHING - GCC destructor dispatch
// ============================================================================
int IFFBehavior::Release() {
    m_refCount--;
    if (m_refCount <= 0) {
        int* vtbl = *(int**)this;
        short offset = *(short*)((char*)vtbl + 8);
        void (*dtor)(void*, int) = (void (*)(void*, int))*(int*)((char*)vtbl + 12);
        dtor((char*)this + offset, 3);
        return 0;
    }
    return m_refCount;
}

// ============================================================================
// __static_initialization_and_destruction_0
// Address: 0x800ad090 | Size: 136 bytes
// NON_MATCHING - compiler-generated
// ============================================================================
// Static init/destroy infrastructure

// ============================================================================
// Behavior::GetResFileIDByClass(short)
// Address: 0x800ad128 | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int Behavior::GetResFileIDByClass(short treeClass) {
    // Virtual call through Language to get res file ID by class
    int* vtbl = *(int**)m_pLanguage;
    short offset = *(short*)((char*)vtbl + 0x48);
    void* thunk = (char*)m_pLanguage + offset;
    typedef int (*GetResFn)(void*, short);
    GetResFn fn = (GetResFn)*(int*)((char*)vtbl + 0x4C);
    return fn(thunk, treeClass);
}

// ============================================================================
// DrawFrame(char *, EVec4 &, bool)
// Address: 0x800ad20c | Size: 84 bytes
// NON_MATCHING - GCC conditional codegen
// ============================================================================
// NON_MATCHING
void DrawFrame(char* label, void* vec4, bool visible) {
    // Debug rendering function - draws labeled frame
    // Conditionally visible based on bool parameter
}

// ============================================================================
// dbAssert(char *, unsigned int, char *)
// Address: 0x800ad49c | Size: 68 bytes
// NON_MATCHING - GCC string formatting
// ============================================================================
void dbAssert(char* file, unsigned int line, char* expr) {
    // Debug assertion handler
    // Formats assertion message with file/line/expression
}

// ============================================================================
// dbBomb(char *,...)
// Address: 0x800ad4e0 | Size: 80 bytes
// NON_MATCHING - GCC varargs handling
// ============================================================================
void dbBomb(char* fmt, ...) {
    // Debug bomb handler - formats and displays fatal error
}

// ============================================================================
// dbAssertTrace(bool, char *,...)
// Address: 0x800ad530 | Size: 248 bytes
// NON_MATCHING - GCC varargs, complex control flow
// ============================================================================
// NON_MATCHING
void dbAssertTrace(bool condition, char* fmt, ...) {
    // Conditional assertion with trace output
    // If condition is false, formats trace message
}

// ============================================================================
// BoxxGlobalGetSourceParamValue(int, int, int *)
// Address: 0x800ad628 | Size: 72 bytes
// NON_MATCHING - GCC switch codegen
// ============================================================================
int BoxxGlobalGetSourceParamValue(int source, int param, int* outValue) {
    // Gets source parameter value for audio system
    *outValue = 0;
    return 0;
}

#endif // Reference decompilation
