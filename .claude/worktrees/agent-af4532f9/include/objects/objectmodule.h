#ifndef OBJECTMODULE_H
#define OBJECTMODULE_H

#include "types.h"

// Forward declarations
class cXObject;
class cXPerson;
class cXObjectImpl;
class ObjSelector;
class ObjectModuleImpl;
class ObjectFolderImpl;
class ObjectFolder;
class ReconBuffer;
class ReconObject;
class iResFile;
class StringBuffer;
class StackElem;
class DialogParam;
class Interaction;
class SimLoopProbe;

// ObjEntryPoint from object.h
typedef int ObjEntryPoint;

// ObjectDataID - identifies object data
struct ObjectDataID {
    u32 m_id;      // +0x00
    short m_index; // +0x04
};

// ChecksumList - linked list of checksums
struct ChecksumList {
    u32 m_checksum;       // +0x00
    void* m_pad04;        // +0x04
    ChecksumList* m_next; // +0x08
};

// ============================================================================
// ObjectFolder - Abstract base class for object folder management
// ============================================================================
class ObjectFolder {
public:
    static ObjectFolder* CreateInstance(void);
    static void DestroyInstance(ObjectFolder* folder);

    virtual ~ObjectFolder(void);
};

// ============================================================================
// GlobalConstantsClient - Client for global constants
// Size: 0x08
// ============================================================================
class GlobalConstantsClient {
public:
    GlobalConstantsClient(short fileID);
    static short GetFileID(void);
    short GetID(void);

    void* m_vtable;    // +0x00
    short m_id;        // +0x04
};

// ============================================================================
// ObjectFolderImpl - Full implementation of ObjectFolder
// Size: 0x694 (1684 bytes)
// ============================================================================
class ObjectFolderImpl : public ObjectFolder {
public:
    ObjectFolderImpl(void);
    virtual ~ObjectFolderImpl(void);

    // Selector management
    int CountSelectors(void);
    ObjSelector* GetSelectorByGUID(int guid);
    ObjSelector* GetNextSelector(ObjSelector* sel);
    ObjSelector* GetSubTileSelector(ObjSelector* sel, int x, int y, int z);
    void DeletingInstance(ObjSelector* sel);

    // File callbacks (empty stubs)
    void CreatingResFile(iResFile* file);
    void DeletingResFile(iResFile* file);

    // Placeholder
    cXObject* GetPlaceholder(void);

    // Type attributes
    void* GetTypeAttrBlock(int typeID);

    // Save/Load
    void Save(iResFile* file);
    void Load(iResFile* file);

    // Commands
    void SuspendObjectFiles(void);
    void ResumeObjectFiles(void);
    int DoCommand(short cmd, int param);

    // Namespace/Behavior
    int IsNamespaceWriteable(unsigned int ns);
    int IsBehaviorWriteable(unsigned int beh);

    // Path/Finder
    const char* GetPath(void);
    void* GetBehaviorFinder(void);
    void* GetObjectsDatabase(void);

    // Data members (partial)
    char _pad[0x550];             // +0x04
    // +0x550: StringBuffer m_path (starts at offset 0x550)
    // +0x660: vector of type attr blocks
    // +0x690: void* m_objectsDatabase
};

// ============================================================================
// ObjectModule - Abstract base class for object management module
// ============================================================================
class ObjectModule {
public:
    typedef int SimFlag;

    static ObjectModule* CreateInstance(void);
    static void DestroyInstance(ObjectModule* mod);

    virtual ~ObjectModule(void);
};

// ============================================================================
// ObjectModuleImpl - Full implementation of ObjectModule
// Size: 0x20E0 (8416 bytes)
// ============================================================================
class ObjectModuleImpl : public ObjectModule {
public:
    ObjectModuleImpl(void);
    virtual ~ObjectModuleImpl(void);

    // Object management
    void ClearKillQueue(void);
    int GetNumObjects(void);
    void AddObject(cXObject* obj, short id);
    cXObject* GetFirst(void);
    ObjectFolder* GetFolder(void);
    cXObject* GetSim(void);
    cXObject* GetPeople(int index);
    int GetNumPeople(void);
    cXObject* GetPortal(int index);
    int GetNumPortals(void);
    cXObject* GetGlobalRoutingSlot(int index);
    int GetNumGlobalRoutingSlots(void);

    // Dialog (empty stubs)
    void EnqueueObjectDialog(cXObject* obj, StackElem* stack, DialogParam* param);
    void EnqueueObjectDialog(ObjSelector* sel, DialogParam* param);

    // Skill/Motive/Personality (empty stubs)
    void SkillAccessed(cXPerson* person, int skill, bool flag);
    void MotiveAccessed(cXPerson* person, int motive, bool flag);
    void PersonalityAccessed(cXPerson* person, int personality, bool flag);
    void RelationshipAccessed(cXObject* objA, cXObject* objB, int rel, bool flag);

    // Tutorial
    cXObject* GetTutorialObject(void);

    // Person selection
    int AdvanceSelectedPerson(int direction);
    cXObject* GetSelectedPerson(int index);

    // Sim flags / idle status
    void SetSimFlag(int simIndex, ObjectModule::SimFlag flag, bool value);
    int GetSimFlag(int simIndex, ObjectModule::SimFlag flag);
    int GetIdleStatus(int simIndex);
    void SetIdleStatus(int simIndex, int status);

    // Buy and build
    int IsBuyAndBuildDisabled(void);

    // Data members (partial)
    char _pad_04[0x18];           // +0x04
    int m_simFlags;               // +0x1c - pointer to flags array
    char _pad_20[0x08];           // +0x20
    void* m_firstObject;          // +0x2c - linked list head
    char _pad_30[0x1FF8];         // +0x30
    // +0x2034: int m_buyBuildDisabledStart
    // +0x2038: int m_buyBuildDisabledEnd
    char _pad_2028[0x30];         // +0x2028
    // +0x2058: vector of people pointers
    // +0x2068: vector of portal pointers
    // +0x2078: vector of global routing slots
    // +0x2088: void* m_tutorialListEntry
    // +0x2090: vector of extra objects
    // +0x20A0: fixed array of 16 named objects
};

// ============================================================================
// ObjectIterator - Iterator for traversing objects
// Size: 0x0C
// ============================================================================
class ObjectIterator {
public:
    enum IterateType {
        ITERATE_ALL = 0
    };

    ObjectIterator(cXObject* start, IterateType type);
    bool operator==(ObjectIterator& other) const;

    cXObject* m_current;   // +0x00
    cXObject* m_start;     // +0x04
    int m_type;            // +0x08
};

// ============================================================================
// ObjFnTable - Object function table
// ============================================================================
class ObjFnTable {
public:
    static ObjFnTable* CreateInstance(void);
    static ObjFnTable* CreateInstance(ObjectDataID& dataID);
    static void DestroyInstance(ObjFnTable* table);

    virtual ~ObjFnTable(void);
};

// ============================================================================
// ObjFnTableQuickData - Quick data wrapper for ObjFnTable
// Size: 0x18 (24 bytes)
// ============================================================================
class ObjFnTableQuickData {
public:
    static ObjFnTableQuickData* CreateInstance(void);

    int GetDataSourceType(void) const;
    void SetTreeID(ObjEntryPoint entry, short id);
    void SetCheckTreeID(ObjEntryPoint entry, short id);
    ObjFnTableQuickData* GetDataID(void) const;
    int SaveDataByID(ObjectDataID& dataID);
    int GetResourceName(StringBuffer& name) const;
    int SetResourceName(StringBuffer& name);
    int AddRef(void);
    int LoadFromIndex(unsigned int index, int param);
    int LoadOnlyNameAndIDFromIndex(unsigned int index, int param);

    void* m_vtable;    // +0x00
    char _pad_04[0x08]; // +0x04
    void* m_entries;   // +0x0c
    void* m_entries2;  // +0x10
    int m_refCount;    // +0x14
};

// ============================================================================
// ObjTestSim - Object test simulation
// Size: 0x1C (28 bytes)
// ============================================================================
class ObjTestSim {
public:
    ObjTestSim(cXPerson* person);

    void SetupInteractionColors(Interaction* interaction, short entryIndex);
    bool IsMenuInProgress(void);

    cXPerson* m_person;     // +0x00
    void* m_objectPtr;      // +0x04
    short m_colors[8];      // +0x08
    void* m_menuObject;     // +0x18

    static void* sCheckTreeModEntry;
};

// ============================================================================
// InteractionList - List of interactions
// Size: 0x14 (20 bytes) + variable node data
// ============================================================================
class InteractionList {
public:
    struct iterator {
        void* m_node; // current node pointer
        iterator& operator++(void);
    };

    InteractionList(void);
    ~InteractionList(void);

    int size(void) const;
    void increment(iterator& it);

    // Node-based linked list
    void* m_head;       // +0x00
    void* m_tail;       // +0x04
    int m_size;         // +0x08
    void* m_pad0c;      // +0x0c
    void* m_pad10;      // +0x10
};

// Free functions
void LDtraceNull(...);
void MLtraceNull(...);
void DStraceNull(...);
bool ObjSelResIDLessThan(ObjSelector* a, ObjSelector* b);
bool findChecksum(unsigned int checksum, ChecksumList& list);

// Templated STL-like functions for objectfolder
template<class Iter, class Comp>
void pop_heap(Iter first, Iter last, Comp comp);
template<class Iter, class Comp>
void partial_sort(Iter first, Iter middle, Iter last, Comp comp);

// SimpleReconObject specializations
class ReconObject {
public:
    virtual ~ReconObject(void);
};

template <class T>
class SimpleReconObject : public ReconObject {
public:
    T* m_impl;     // +0x04
    short m_type;  // +0x08

    ~SimpleReconObject(void);
    void DoStream(ReconBuffer* buf, int flags);
    short GetType(void);
};

// StubObject
class StubObject {
public:
    static int GenerateHash(void);
};

// External: operator new/delete
extern void* operator new(u32 size);
extern void operator delete(void* ptr);

// Forward declarations for SimpleReconObject specializations
class ThumbnailLoader;
class ObjectSaveTypeTable;

#endif // OBJECTMODULE_H
