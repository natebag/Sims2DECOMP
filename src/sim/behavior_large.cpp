// behavior_large.cpp - Large functions (257-1024 bytes) from behavior.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\behavior.obj
//
// 8 large functions decompiled from behavior.obj
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation differences
//   - GCC destructor ABI (s_cacheTreesRefCount cleanup loop)
//   - SDA-relative addressing

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class Behavior;
class IFFBehavior;
class Language;
class ObjSelector;
class ObjectDataBehaviorTree;
class BehaviorNode;
class StringBuffer;
class ReconBuffer;

// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);

#if 0  // Reference decompilation - not compiled

// ============================================================================
// Behavior::~Behavior(void)
// Address: 0x800AB314 | Size: 396 bytes
// NON_MATCHING - GCC destructor ABI, cache cleanup loop codegen
//
// Decrements s_cacheTreesRefCount. When it reaches 0, iterates through
// s_cachedTrees (a vector of pointers at r13-0x7D7C) and calls Release()
// on each non-null entry, then clears the vector. Finally swaps internal
// vector storage between stack temporaries and the cached trees vector.
// ============================================================================
Behavior::~Behavior() {
    // Set vtable to Behavior's vtable
    *(void**)this = (void*)0x8045E878;

    // Decrement ref count
    int refCount = s_cacheTreesRefCount - 1;
    s_cacheTreesRefCount = refCount;

    if (refCount <= 0) {
        // s_cachedTrees is at a SDA-relative offset
        void** cachedBegin = s_cachedTrees.begin();
        void** cachedEnd = s_cachedTrees.end();
        int count = (int)(cachedEnd - cachedBegin);

        if (count > 0) {
            for (int i = 0; i < count; i++) {
                void* entry = cachedBegin[i];
                if (entry != 0) {
                    // Virtual call: entry->Release()
                    int* vtbl = *(int**)entry;
                    short offset = *(short*)((char*)vtbl + 0x18);
                    void* fn = *(void**)((char*)vtbl + 0x1C);
                    ((void(*)(void*))fn)((char*)entry + offset);
                    cachedBegin[i] = 0;
                }
            }
        }

        // Clear and swap the cached trees vector with empty temp
        void* tempVec[3] = {0, 0, 0};
        void* tempVec2[3];

        // Swap begin/end/capacity pointers between temp and cached
        tempVec2[0] = s_cachedTrees.m_begin;
        tempVec2[1] = s_cachedTrees.m_end;
        tempVec2[2] = s_cachedTrees.m_capacity;

        s_cachedTrees.m_begin = tempVec[0];
        s_cachedTrees.m_end = tempVec[1];
        s_cachedTrees.m_capacity = tempVec[2];

        tempVec[0] = tempVec2[0];
        tempVec[1] = tempVec2[1];
        tempVec[2] = tempVec2[2];

        // Free old storage
        if (tempVec[0] != 0) {
            operator_delete(tempVec[0]);
        }
    }
}

// ============================================================================
// Behavior::GetNodeRef(short, short, BehaviorNode **)
// Address: 0x800AB5BC | Size: 504 bytes
// NON_MATCHING - GCC register alloc, cache search loop codegen
//
// Searches the s_cachedTrees vector for a tree matching the given scope/treeID.
// If found, inserts it at the front of the cache (shifting others). Then calls
// GetNode on the tree to retrieve the specified node reference.
// ============================================================================
int Behavior::GetNodeRef(short treeID, short nodeIndex, BehaviorNode** ppNode) {
    if (ppNode == 0) {
        return 0;
    }

    *ppNode = 0;
    void* foundTree = 0;

    // Get tree count for this scope
    int* vtbl = *(int**)this;
    int treeCount = ((int(*)(void*, short))*(void**)((char*)vtbl + 0x34))
                    ((char*)this + *(short*)((char*)vtbl + 0x30), treeID);

    // Search s_cachedTrees for a matching entry
    void** cachedBegin = s_cachedTrees.begin();
    void** cachedEnd = s_cachedTrees.end();
    int cacheCount = (int)(cachedEnd - cachedBegin);
    int foundIdx = 0;

    if (cacheCount > 0) {
        for (int i = 0; i < cacheCount; i++) {
            void* entry = cachedBegin[i];
            // Compare dataID at entry+0x58 with computed ID
            if (CompareDataID(entry + 0x58, treeID) == 0) {
                continue;
            }
            if (foundIdx > 0) {
                // Shift entries down to make room at front
                for (int j = foundIdx; j > 0; j--) {
                    cachedBegin[j] = cachedBegin[j-1];
                }
            }
            cachedBegin[0] = entry;
            foundTree = entry;
            break;
        }
    }

    if (foundTree == 0) {
        // Tree not in cache - load it
        ObjectDataBehaviorTree* tree = 0;
        int result = GetTree(treeID, &tree, false);
        if (tree == 0) {
            return 0;
        }
        foundTree = tree;

        // Insert into cache
        if (cacheCount > 0) {
            // Shift all entries right by 1
            for (int j = cacheCount - 1; j > 0; j--) {
                cachedBegin[j] = cachedBegin[j-1];
            }
        }
        cachedBegin[0] = foundTree;
    }

    // Get node from tree
    BehaviorNode* node = ((ObjectDataBehaviorTree*)foundTree)->GetNode(nodeIndex);
    if (node != 0) {
        *ppNode = node;
        return 1;
    }
    return 0;
}

// ============================================================================
// Behavior::IsNodeReachable(short, int)
// Address: 0x800AB7B4 | Size: 268 bytes
// NON_MATCHING - GCC register alloc, loop codegen
//
// Checks if a node is reachable from the tree's entry point by traversing
// the behavior tree graph. Walks through true/false exit links starting
// from node 0 and checks if the target node index is encountered.
// ============================================================================
int Behavior::IsNodeReachable(short treeID, int nodeIndex) {
    ObjectDataBehaviorTree* tree = 0;
    int result = GetTree(treeID, &tree, false);
    if (tree == 0) {
        return 0;
    }

    short numNodes = tree->GetNumNodes();
    if (numNodes <= 0) {
        return 0;
    }

    // Check each node's exit links to see if nodeIndex is reachable
    for (int i = 0; i < numNodes; i++) {
        BehaviorNode* node = tree->GetNode(i);
        if (node == 0) continue;

        // Check true exit (offset +0x08 in node)
        short trueExit = *(short*)((char*)node + 0x08);
        if (trueExit == nodeIndex) {
            return 1;
        }

        // Check false exit (offset +0x0A in node)
        short falseExit = *(short*)((char*)node + 0x0A);
        if (falseExit == nodeIndex) {
            return 1;
        }
    }

    return 0;
}

// ============================================================================
// Behavior::IsSingleExit(short, short)
// Address: 0x800ABB14 | Size: 308 bytes
// NON_MATCHING - GCC virtual dispatch, branch codegen
//
// Checks if a behavior node at the given tree/node index has only a single
// exit path. Calls through the Language vtable to check the node's primitive
// type, then examines exit links.
// ============================================================================
int Behavior::IsSingleExit(short treeID, short nodeIndex) {
    ObjectDataBehaviorTree* tree = 0;
    int result = GetTree(treeID, &tree, false);
    if (tree == 0) {
        return 0;
    }

    BehaviorNode* node = tree->GetNode(nodeIndex);
    if (node == 0) {
        return 0;
    }

    // Check through Language virtual table
    Language* lang = m_pLanguage;
    if (lang != 0) {
        return lang->IsSingleExit(node);
    }

    // Fallback: check if true and false exits are the same
    short trueExit = *(short*)((char*)node + 0x08);
    short falseExit = *(short*)((char*)node + 0x0A);
    return (trueExit == falseExit) ? 1 : 0;
}

// ============================================================================
// Behavior::GetTreeName(short, StringBuffer &)
// Address: 0x800AC4A4 | Size: 260 bytes
// NON_MATCHING - GCC register alloc, string handling
//
// Retrieves the name of a behavior tree by its ID. Loads the tree,
// then gets its resource name via virtual call.
// ============================================================================
int Behavior::GetTreeName(short treeID, StringBuffer& outName) {
    ObjectDataBehaviorTree* tree = 0;
    int result = GetTree(treeID, &tree, false);
    if (tree == 0) {
        return 0;
    }

    // Virtual call: tree->GetResourceName(outName)
    int* vtbl = *(int**)tree;
    short offset = *(short*)((char*)vtbl + 0x48);
    void* fn = *(void**)((char*)vtbl + 0x4C);
    return ((int(*)(void*, StringBuffer&))fn)((char*)tree + offset, outName);
}

// ============================================================================
// Behavior::Init(Language *, ObjSelector *)
// Address: 0x800AC650 | Size: 480 bytes
// NON_MATCHING - GCC virtual dispatch, constructor/init codegen
//
// Initializes the Behavior with a Language and ObjSelector. Sets up
// the cached trees vector if this is the first reference (refCount==0).
// Increments s_cacheTreesRefCount. Stores language and owner pointers.
// ============================================================================
void Behavior::Init(Language* lang, ObjSelector* owner) {
    m_pLanguage = lang;
    m_pOwner = owner;

    // Increment cache ref count
    s_cacheTreesRefCount++;

    if (s_cacheTreesRefCount == 1) {
        // First reference - initialize the cache
        // Allocate space for cached tree pointers
        int cacheSize = 6;  // Cache holds up to 6 trees

        void** cachedBegin = s_cachedTrees.begin();
        void** cachedEnd = s_cachedTrees.end();
        int currentSize = (int)(cachedEnd - cachedBegin);

        if (currentSize < cacheSize) {
            // Need to grow
            void* newMem = operator_new(cacheSize * 4);
            // Copy existing
            for (int i = 0; i < currentSize; i++) {
                ((void**)newMem)[i] = cachedBegin[i];
            }
            // Zero new entries
            for (int i = currentSize; i < cacheSize; i++) {
                ((void**)newMem)[i] = 0;
            }
            // Free old
            if (cachedBegin != 0) {
                operator_delete(cachedBegin);
            }
            s_cachedTrees.m_begin = newMem;
            s_cachedTrees.m_end = (char*)newMem + cacheSize * 4;
            s_cachedTrees.m_capacity = (char*)newMem + cacheSize * 4;
        }
    }
}

// ============================================================================
// IFFBehavior::GetTreeByIndex(int, short, ObjectDataBehaviorTree **)
// Address: 0x800ACD44 | Size: 288 bytes
// NON_MATCHING - GCC virtual dispatch, return value handling
//
// Gets a behavior tree by its index within a given scope. Computes the
// base ID for the scope, adds the index, and calls GetTree to load it.
// Returns the tree through the output pointer parameter.
// ============================================================================
int IFFBehavior::GetTreeByIndex(int index, short scope, ObjectDataBehaviorTree** ppTree) {
    if (ppTree == 0) {
        return -1;
    }

    *ppTree = 0;

    // Get the base tree ID for this scope
    int baseID = GetBaseID(scope);
    if (baseID < 0) {
        return -1;
    }

    // Compute actual tree ID
    short treeID = (short)(baseID + index);

    // Load the tree
    ObjectDataBehaviorTree* tree = 0;
    int result = GetTree(treeID, &tree, false);
    if (result < 0 || tree == 0) {
        return result;
    }

    *ppTree = tree;
    return 0;
}

// ============================================================================
// IFFBehavior::GetTreeIDByName(char *)
// Address: 0x800ACE64 | Size: 332 bytes
// NON_MATCHING - GCC string compare, loop codegen
//
// Searches for a behavior tree by name. Iterates through all trees in
// the local/semiglobal/global scopes, comparing tree names against the
// target string. Returns the tree ID if found, -1 if not.
// ============================================================================
int IFFBehavior::GetTreeIDByName(char* name) {
    if (name == 0) {
        return -1;
    }

    // Search through scopes: local (0), semiglobal (1), global (2)
    for (int scope = 0; scope < 3; scope++) {
        int baseID = GetBaseID((short)scope);
        int maxID = GetMaxID((short)scope);

        if (baseID < 0 || maxID < 0) {
            continue;
        }

        for (int id = baseID; id <= maxID; id++) {
            ObjectDataBehaviorTree* tree = 0;
            int result = GetTree((short)id, &tree, false);
            if (tree == 0) {
                continue;
            }

            // Get tree name via virtual call
            char treeName[64];
            StringBuffer nameBuf;
            // Initialize nameBuf with treeName buffer
            int* vtbl = *(int**)tree;
            short offset = *(short*)((char*)vtbl + 0x48);
            void* fn = *(void**)((char*)vtbl + 0x4C);
            ((int(*)(void*, void*))fn)((char*)tree + offset, &nameBuf);

            // Compare names
            if (strcmp(treeName, name) == 0) {
                return id;
            }
        }
    }

    return -1;
}

#endif // Reference decompilation
