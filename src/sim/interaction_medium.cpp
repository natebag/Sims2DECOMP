// interaction_medium.cpp - Medium functions (65-256 bytes) from interaction.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\interaction.obj
//
// 14 medium functions decompiled from interaction.obj
//
// NON_MATCHING causes:
//   - GCC uses stw/lwz individually, SN uses stmw/lmw
//   - GCC reorders field stores
//   - GCC tail-calls where SN uses full stack frame
//   - Virtual dispatch codegen differs (bctr vs blrl)

#include "types.h"

// Forward declarations - this file is standalone to avoid header conflicts
// All functions are NON_MATCHING stubs for documentation purposes


// External functions
extern void BString2_ctor(void* str);          // 0x800a1ad4
extern void BString2_dtor(void* str, int);     // 0x800a1d70
extern void BString2_copy(void* dst, void* src); // 0x800a1dc8
extern void BString2_assign_cstr(void* str, const char* cstr); // 0x800a24f8
extern void BString2_concat(void* str, const char* cstr); // 0x800a1e60
extern void BString2_from_estring(void* dst, void* src); // 0x800a1fc4
extern int BString2_isEmpty(void* str);        // 0x800a4858
extern void* operator_new(unsigned int size);  // 0x802d11e8
extern void operator_delete(void* ptr);        // 0x802d1254

#if 0  // Reference decompilation - not compiled (header conflicts with existing declarations)

// ============================================================================
// Interaction::operator=(Interaction &)
// Address: 0x800c1068 | Size: 216 bytes
// NON_MATCHING - GCC register allocation (r9/r0 alternation differs)
// ============================================================================
Interaction& Interaction::operator=(Interaction& other) {
    // Copy flags first
    m_flags = other.m_flags;
    // Copy type
    m_type = other.m_type;
    // Copy priority
    m_priority = other.m_priority;
    // Copy person pointer
    m_pPerson = other.m_pPerson;
    // Copy stack object
    m_pStackObject = other.m_pStackObject;
    // Copy icon object
    m_pIconObject = other.m_pIconObject;
    // Copy tree tab entry index
    m_treeTabEntryIndex = other.m_treeTabEntryIndex;
    // Copy stack vars (4 shorts)
    m_stackVars[0] = other.m_stackVars[0];
    m_stackVars[1] = other.m_stackVars[1];
    m_stackVars[2] = other.m_stackVars[2];
    m_stackVars[3] = other.m_stackVars[3];
    // Copy unique ID
    m_uniqueID = other.m_uniqueID;
    // Copy tree ID
    m_treeID = other.m_treeID;
    // Copy attenuation
    m_attenuation = other.m_attenuation;
    // Copy name (BString2 assignment)
    BString2_copy(&m_name, &other.m_name);
    // Copy local vars
    m_pLocalVars = 0;
    int count = other.m_localVarsCount;
    if (count != 0) {
        SetLocalVars(other.m_pLocalVars, count);
    } else {
        m_localVarsCount = 0;
        m_pLocalVars = 0;
    }
    return *this;
}

// ============================================================================
// Interaction::Interaction(void)
// Address: 0x800c1140 | Size: 144 bytes
// NON_MATCHING - GCC register allocation, store ordering
// ============================================================================
Interaction::Interaction() {
    m_pPerson = 0;
    m_pStackObject = 0;
    m_pIconObject = 0;
    m_priority = 0;
    m_treeID = 0;
    // vtable at offset 64 set to Interaction vtable 0x8045f718
    m_treeTabEntryIndex = -1;
    // attenuation loaded from .sdata2 float constant
    m_attenuation = 1.0f;
    // BString2 constructor call
    BString2_ctor(&m_name);
    m_pLocalVars = 0;
    m_uniqueID = 0;
    m_type = 0;
    m_stackVars[0] = 0;
    m_stackVars[1] = 0;
    m_stackVars[2] = 0;
    m_stackVars[3] = 0;
    m_flags = 0;
    m_localVarsCount = 0;
}

// ============================================================================
// Interaction::Interaction(Interaction &)
// Address: 0x800c11d0 | Size: 92 bytes
// NON_MATCHING - GCC register allocation
// ============================================================================
Interaction::Interaction(Interaction& other) {
    // vtable set
    // BString2 constructor
    BString2_ctor(&m_name);
    m_pLocalVars = 0;
    m_localVarsCount = 0;
    // Call operator= to copy all fields
    *this = other;
}

// ============================================================================
// Interaction::Interaction(cXPerson *, cXObject *, int)
// Address: 0x800c122c | Size: 204 bytes
// NON_MATCHING - GCC register allocation, store ordering
// ============================================================================
Interaction::Interaction(cXPerson* person, cXObject* stackObj, int treeTabIdx) {
    // vtable set
    // BString2 constructor
    BString2_ctor(&m_name);
    m_type = 2;
    m_priority = 100;
    m_flags = 0;
    m_pPerson = person;
    if (stackObj == 0) {
        m_pIconObject = stackObj;
        m_treeTabEntryIndex = -1;
    } else {
        m_pIconObject = stackObj;
        m_treeTabEntryIndex = treeTabIdx;
    }
    m_pStackObject = stackObj;
    // Clear flags bit 0
    m_flags = m_flags & ~1;
    m_stackVars[3] = 0;
    m_attenuation = 1.0f;
    m_pLocalVars = 0;
    m_stackVars[0] = 0;
    m_stackVars[1] = 0;
    m_stackVars[2] = 0;
    m_uniqueID = 0;
    m_treeID = 0;
    m_localVarsCount = 0;
}

// ============================================================================
// Interaction::~Interaction(void)
// Address: 0x800c171c | Size: 100 bytes
// NON_MATCHING - GCC destructor ABI, vtable set order
// ============================================================================
Interaction::~Interaction() {
    // vtable set to Interaction vtable
    // Free local vars if allocated
    if (m_pLocalVars != 0) {
        operator_delete(m_pLocalVars);
    }
    // Destroy BString2 name
    BString2_dtor(&m_name, 2);
    // If bit 0 of delete flag set, call operator delete on this
}

// ============================================================================
// Interaction::SetLocalVars(short *, int)
// Address: 0x800c17a4 | Size: 136 bytes
// NON_MATCHING - GCC loop codegen differs, register allocation
// ============================================================================
void Interaction::SetLocalVars(short* vars, int count) {
    // Free existing local vars
    if (m_pLocalVars != 0) {
        operator_delete(m_pLocalVars);
    }
    // Store count
    m_localVarsCount = count;
    // Allocate new array: (count + 3) << 1 bytes (rounds up to 4-byte alignment)
    int allocSize = (count + 3) << 1;
    m_pLocalVars = (short*)operator_new(allocSize);
    // Copy vars
    int i = 0;
    while (i < m_localVarsCount) {
        m_pLocalVars[i] = vars[i];
        i++;
    }
}

// ============================================================================
// Interaction::GetEntry(void) const
// Address: 0x800c182c | Size: 112 bytes
// NON_MATCHING - GCC virtual dispatch pattern differs
// Gets TreeTableEntry from stack object's selector
// ============================================================================
void* Interaction::GetEntry() const {
    cXObject* stackObj = m_pStackObject;
    if (stackObj == 0) {
        return 0;
    }
    // Virtual call: stackObj->GetSelector()
    int* vtbl1 = *(int**)((char*)stackObj + 4);
    short offset1 = *(short*)((char*)vtbl1 + 0x360);
    void* thunk1 = (char*)stackObj + offset1;
    typedef void* (*GetSelectorFn)(void*);
    GetSelectorFn fn1 = (GetSelectorFn)*(int*)((char*)vtbl1 + 0x364);
    void* selector = fn1(thunk1);
    // Virtual call: selector->GetEntry(treeTabEntryIndex)
    int* vtbl2 = *(int**)selector;
    short offset2 = *(short*)((char*)vtbl2 + 0x88);
    void* thunk2 = (char*)selector + offset2;
    typedef void* (*GetEntryFn)(void*, int);
    GetEntryFn fn2 = (GetEntryFn)*(int*)((char*)vtbl2 + 0x8C);
    return fn2(thunk2, m_treeTabEntryIndex);
}

// ============================================================================
// Interaction::GetName(void) const
// Address: 0x800c18b0 | Size: 176 bytes
// NON_MATCHING - GCC virtual dispatch, string operations
// ============================================================================
void* Interaction::GetName() const {
    // Check if name string is empty
    int empty = BString2_isEmpty((void*)&m_name);
    if (empty == 0) {
        // Name is not empty, get entry and check for name
        void* entry = GetEntry();
        if (entry != 0) {
            // Virtual call: entry->HasName() (vtable offset 0xC8/0xCC)
            int* vtbl = *(int**)entry;
            short offset = *(short*)((char*)vtbl + 0xC8);
            void* thunk = (char*)entry + offset;
            typedef int (*HasNameFn)(void*);
            HasNameFn fn = (HasNameFn)*(int*)((char*)vtbl + 0xCC);
            int hasName = fn(thunk);
            if (hasName != 0) {
                // Concat with format string
                BString2_concat((void*)&m_name, " ");
            }
            // Virtual call: entry->GetLabel() (vtable offset 0x1A0/0x1A4)
            int* vtbl2 = *(int**)entry;
            short offset2 = *(short*)((char*)vtbl2 + 0x1A0);
            void* thunk2 = (char*)entry + offset2;
            typedef void* (*GetLabelFn)(void*);
            GetLabelFn fn2 = (GetLabelFn)*(int*)((char*)vtbl2 + 0x1A4);
            void* label = fn2(thunk2);
            BString2_from_estring((void*)&m_name, label);
        }
    }
    // Clear NAME_CHANGED flag
    m_flags = m_flags & ~(1 << 7);
    return (void*)&m_name;
}

// ============================================================================
// Interaction::GetCTilePt(void) const
// Address: 0x800c1cbc | Size: 100 bytes
// NON_MATCHING - SDA-relative addressing, virtual dispatch
// ============================================================================
// NON_MATCHING
void* Interaction::GetCTilePt() const {
    // Uses SDA-relative global for cached tile point
    // Checks guard variable, calls GetStackObject(), dispatches through
    // its vtable to get tile position, caches result
    return 0; // placeholder - complex SDA-relative caching
}

// ============================================================================
// Motives::Init(void)
// Address: 0x800c27fc | Size: 156 bytes
// NON_MATCHING - GCC loop codegen (bdnz counter loop)
// ============================================================================
void Motives::Init() {
    // Check SDA global for motive system init
    // Virtual call through global motive manager to get count
    // Initialize 16 motive values to default float from .sdata2
    // Initialize 16 motive effect values to same default
    // Clear motive dirty flag at offset +0x80
    float defaultVal = 0.0f; // from .sdata2 at r9-0xa3a0
    for (int i = 0; i < 16; i++) {
        m_motives[i] = defaultVal;
    }
    for (int i = 0; i < 16; i++) {
        m_motiveEffects[i] = defaultVal;
    }
    m_dirtyFlags = 0;
}

// ============================================================================
// Motives::Cleanup(void)
// Address: 0x800c2c10 | Size: 192 bytes
// NON_MATCHING - GCC float comparison codegen, loop structure
// ============================================================================
void Motives::Cleanup() {
    float zeroVal = 0.0f; // from .sdata2
    float maxVal = 100.0f; // from .sdata2
    float minVal = -100.0f; // from .sdata2
    for (int i = 0; i < 16; i++) {
        // Get motive system state
        // If motive system is active and index > 0, zero out the motive
        float val = m_motives[i];
        // Clamp to max
        if (val > maxVal) {
            m_motives[i] = maxVal;
        }
        // Clamp to min
        val = m_motives[i];
        if (val < minVal) {
            m_motives[i] = minVal;
        }
        // Copy to effects array
        m_motiveEffects[i] = m_motives[i];
    }
}

// ============================================================================
// Interaction::SetName(int, int)
// Address: 0x800c199c | Size: 204 bytes
// NON_MATCHING - SDA-relative, virtual dispatch chain
// Sets name from string table using tree tab entry
// ============================================================================
// NON_MATCHING
void Interaction::SetName(int stringSetID, int stringIndex) {
    // Load global string manager from SDA (r13-21508)
    // If null, return
    // Virtual call to get string resource
    // Then virtual call to get string entry by index
    // Create temp BString2, assign string, call SetName(BString2&), destroy temp
}

// ============================================================================
// __static_initialization_and_destruction_0
// Address: 0x800c2cd0 | Size: 76 bytes
// NON_MATCHING - compiler-generated static init
// ============================================================================
// Cannot decompile - compiler infrastructure

// ============================================================================
// MotiveCurveSet::LoadFromStringSet(char **, int)
// Address: 0x800c2e98 | Size: 116 bytes
// NON_MATCHING - GCC loop/string parsing differs
// ============================================================================
// NON_MATCHING
void MotiveCurveSet::LoadFromStringSet(char** strings, int count) {
    // Parses string set to load motive curve parameters
    // Complex string parsing - cannot match without full context
}

#endif // Reference decompilation
