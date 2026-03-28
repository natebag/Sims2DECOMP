// behaviortree_large.cpp - Large functions (257-1024 bytes) from behaviortree.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\behaviortree.obj
//
// 6 large functions decompiled from behaviortree.obj
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation differences
//   - Pool buffer is data, not code
//   - SDA-relative addressing

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class ObjectDataBehaviorTree;
class ResourceBehaviorTree;
class IFFBehaviorTree;
class StringBuffer;
struct ObjectDataID;
struct BehaviorTreeHeader;
class ReconBuffer;

// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);

// Pool data
extern char g_poolResourceBehaviorTree[];
extern char g_rbTreePoolBuffer[];

#if 0  // Reference decompilation - not compiled

// ============================================================================
// ResourceBehaviorTree::LoadFromIndex(unsigned int, int)
// Address: 0x8015ACA0 | Size: 328 bytes
// NON_MATCHING - GCC virtual dispatch, resource loading codegen
//
// Loads a behavior tree resource from the resource system by index.
// Calls the resource manager to find the data, then parses the header
// and node data. Sets up the tree's internal pointers.
// ============================================================================
int ResourceBehaviorTree::LoadFromIndex(unsigned int index, int scope) {
    // Get resource file from scope
    void* resFile = 0;
    int result = GetResFile(scope, &resFile);
    if (result < 0 || resFile == 0) {
        return -1;
    }

    // Load raw data from resource
    void* rawData = 0;
    int dataSize = 0;
    result = LoadRawResource(resFile, index, &rawData, &dataSize);
    if (result < 0 || rawData == 0) {
        return -1;
    }

    // Parse header
    BehaviorTreeHeader* header = (BehaviorTreeHeader*)rawData;
    m_pHeader = header;

    // Set resource ID
    m_resID = (short)index;

    // Set name from resource
    char nameBuf[64];
    result = GetResourceNameFromFile(resFile, index, nameBuf, 64);
    if (result >= 0) {
        // Copy name to internal buffer
        // StringBuffer set at offset +0x0C
        char* namePtr = (char*)this + 0x0C;
        StringBuffer_set(namePtr, nameBuf);
    }

    // Build data ID
    m_dataID.m_field0 = scope;
    m_dataID.m_field4 = (int)index;

    // Clear cached state
    m_field60 = 0;

    return 0;
}

// ============================================================================
// ResourceBehaviorTree::LoadFromDataID(ObjectDataID &)
// Address: 0x8015AE1C | Size: 296 bytes
// NON_MATCHING - GCC register alloc, virtual dispatch
//
// Loads a behavior tree from a data ID. Extracts the scope and index
// from the ObjectDataID, then delegates to LoadFromIndex.
// ============================================================================
int ResourceBehaviorTree::LoadFromDataID(ObjectDataID& id) {
    int scope = id.m_field0;
    unsigned int index = (unsigned int)id.m_field4;

    // Check if already loaded with same ID
    if (m_dataID.m_field0 == scope && m_dataID.m_field4 == (int)index) {
        // Already loaded - verify data is still valid
        if (m_pHeader != 0) {
            return 0;
        }
    }

    // Clear existing data
    if (m_pHeader != 0) {
        // Release old header if we own it
        m_pHeader = 0;
    }

    // Load from index
    int result = LoadFromIndex(index, scope);
    if (result < 0) {
        return result;
    }

    // Store data ID
    m_dataID = id;

    return 0;
}

// ============================================================================
// ResourceBehaviorTree::GetFromDataID(ObjectDataID &)
// Address: 0x8015AF44 | Size: 296 bytes
// NON_MATCHING - GCC register alloc, virtual dispatch
//
// Gets (or loads) a behavior tree from a data ID. Similar to LoadFromDataID
// but may use cached data. First checks the pool for an existing instance
// with matching ID, otherwise creates a new one and loads it.
// ============================================================================
int ResourceBehaviorTree::GetFromDataID(ObjectDataID& id) {
    int scope = id.m_field0;
    unsigned int index = (unsigned int)id.m_field4;

    // Search pool for existing tree with this ID
    // Pool is at g_poolResourceBehaviorTree
    void* pool = g_poolResourceBehaviorTree;
    if (pool != 0) {
        // Walk pool entries looking for matching data ID
        int poolCount = *(int*)pool;
        char* entries = (char*)pool + 4;
        for (int i = 0; i < poolCount; i++) {
            ResourceBehaviorTree* cached = *(ResourceBehaviorTree**)(entries + i * 4);
            if (cached != 0) {
                ObjectDataID cachedID;
                cachedID.m_field0 = cached->m_dataID.m_field0;
                cachedID.m_field4 = cached->m_dataID.m_field4;
                if (cachedID.m_field0 == scope && cachedID.m_field4 == (int)index) {
                    // Found match - copy data
                    m_pHeader = cached->m_pHeader;
                    m_dataID = cached->m_dataID;
                    m_resID = cached->m_resID;
                    return 0;
                }
            }
        }
    }

    // Not cached - load fresh
    return LoadFromDataID(id);
}

// ============================================================================
// IFFBehaviorTree::LoadFromIndex(unsigned int, int)
// Address: 0x8015B3E4 | Size: 268 bytes
// NON_MATCHING - GCC register alloc, IFF resource loading
//
// Loads a behavior tree from an IFF resource file by index. Similar to
// ResourceBehaviorTree::LoadFromIndex but uses IFF file format parsing.
// ============================================================================
int IFFBehaviorTree::LoadFromIndex(unsigned int index, int scope) {
    // Get IFF resource file
    void* resFile = 0;
    int result = GetResFile(scope, &resFile);
    if (result < 0 || resFile == 0) {
        return -1;
    }

    // Load from IFF chunk
    void* rawData = 0;
    int dataSize = 0;
    result = LoadIFFChunk(resFile, index, &rawData, &dataSize);
    if (result < 0 || rawData == 0) {
        return -1;
    }

    // Parse header
    m_pHeader = (BehaviorTreeHeader*)rawData;
    m_resID = (short)index;

    // Build data ID
    m_dataID.m_field0 = scope;
    m_dataID.m_field4 = (int)index;

    return 0;
}

// ============================================================================
// IFFBehaviorTree::SaveDataByID(ObjectDataID &)
// Address: 0x8015B650 | Size: 456 bytes
// NON_MATCHING - GCC register alloc, serialization codegen
//
// Saves a behavior tree to an IFF resource file. Serializes the header
// and all node data, then writes the name and data ID. Handles version
// stamping and resource file management.
// ============================================================================
int IFFBehaviorTree::SaveDataByID(ObjectDataID& id) {
    int scope = id.m_field0;
    unsigned int index = (unsigned int)id.m_field4;

    // Get resource file for writing
    void* resFile = 0;
    int result = GetResFile(scope, &resFile);
    if (result < 0 || resFile == 0) {
        return -1;
    }

    // Validate header exists
    if (m_pHeader == 0) {
        return -1;
    }

    // Calculate total data size: header + nodes
    short numNodes = m_pHeader->m_numNodes;
    int dataSize = 0x0C + (numNodes * 12);  // 12 bytes per node

    // Allocate output buffer
    void* outBuf = operator_new(dataSize);
    if (outBuf == 0) {
        return -1;
    }

    // Copy header (first 12 bytes)
    *(short*)((char*)outBuf + 0) = m_pHeader->m_structVersion;
    *(short*)((char*)outBuf + 2) = m_pHeader->m_numNodes;
    *(u8*)((char*)outBuf + 4) = m_pHeader->m_type;
    *(u8*)((char*)outBuf + 5) = m_pHeader->m_numParams;
    *(u8*)((char*)outBuf + 6) = m_pHeader->m_numLocals;
    *(u8*)((char*)outBuf + 7) = 0;
    *(int*)((char*)outBuf + 8) = m_pHeader->m_treeVersionData;

    // Copy node data
    char* srcNodes = (char*)m_pHeader + 0x0C;
    char* dstNodes = (char*)outBuf + 0x0C;
    for (int i = 0; i < numNodes * 12; i++) {
        dstNodes[i] = srcNodes[i];
    }

    // Write to resource file
    result = WriteIFFChunk(resFile, index, outBuf, dataSize);

    // Set the name in the resource
    char* namePtr = (char*)this + 0x0C;
    SetResourceNameInFile(resFile, index, namePtr);

    // Free temp buffer
    operator_delete(outBuf);

    // Update data ID
    m_dataID = id;

    return result;
}

// ============================================================================
// g_rbTreePoolBuffer
// Address: 0x804874D8 | Size: 584 bytes
// This is BSS/data, not a function - pool allocation buffer for
// ResourceBehaviorTree instances. 584 bytes = enough for ~8 pooled trees.
// ============================================================================
// char g_rbTreePoolBuffer[584]; // Defined in data section

#endif // Reference decompilation
