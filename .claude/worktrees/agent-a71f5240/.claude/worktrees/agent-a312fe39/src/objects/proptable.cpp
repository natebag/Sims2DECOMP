// proptable.cpp - Decompiled small functions from proptable.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\proptable.obj
//
// 9 small functions (<=64 bytes) decompiled

#include "objects/proptable.h"

// Placement new for -fno-exceptions build
inline void* operator new(unsigned int, void* p) { return p; }

// ============================================================================
// External references
// ============================================================================
extern void* operator_new(unsigned int size);    // 0x802D11B0
extern void operator_delete(void* ptr);          // 0x802D1220

// PropTableImpl vtable at 0x80464100
// PropTable vtable at 0x80464140

// ============================================================================
// PropTable::CreateInstance
// Address: 0x80132810, Size: 40 bytes
// NON_MATCHING - new + constructor call pattern
// Allocates and constructs a PropTableImpl
// ============================================================================
PropTable* PropTable::CreateInstance() {
    PropTableImpl* impl = (PropTableImpl*)operator_new(8);
    new (impl) PropTableImpl();
    return impl;
}

// ============================================================================
// PropTableImpl::PropTableImpl
// Address: 0x80132878, Size: 28 bytes
// MATCHING
// Sets vtable and zeroes data pointer
// ============================================================================
PropTableImpl::PropTableImpl() {
    // vtable = PropTableImpl vtable (0x80464100)
    m_data = 0;
}

// ============================================================================
// PropTable::DestroyInstance
// Address: 0x80132838, Size: 64 bytes
// NON_MATCHING - virtual call dispatch pattern (vtable + offset)
// Destroys a PropTable via virtual destructor
// ============================================================================
void PropTable::DestroyInstance(PropTable* table) {
    if (table != 0) {
        // Virtual destructor dispatch: vtable[2] offset, vtable[3] func
        delete table;
    }
}

// ============================================================================
// PropTableImpl::~PropTableImpl
// Address: 0x80132894, Size: 52 bytes
// NON_MATCHING - vtable reset and conditional delete
// ============================================================================
PropTableImpl::~PropTableImpl() {
    // vtable reset to PropTable base vtable
    // conditional operator delete based on flags
}

// ============================================================================
// PropTable::~PropTable
// Address: 0x803ABBDC, Size: 52 bytes
// NON_MATCHING - vtable reset and conditional delete
// Same pattern as PropTableImpl::~PropTableImpl but with base vtable
// ============================================================================
PropTable::~PropTable() {
    // vtable = PropTable vtable (0x80464140)
    // if (flags & 1) operator_delete(this)
}

// ============================================================================
// PropTableImpl::GetEntry
// Address: 0x80132950, Size: 52 bytes
// NON_MATCHING - bounds check and array access pattern
// Returns entry at given index, with bounds checking
// ============================================================================
void* PropTableImpl::GetEntry(int index) {
    void** entries = m_data->m_entries;
    int count = 0;
    if (entries != 0) {
        count = ((int*)entries)[-1];  // count stored before array
    }
    if (index >= count) {
        return 0;
    }
    return entries[index];
}

// ============================================================================
// PropTableImpl::GetID
// Address: 0x80132984, Size: 12 bytes
// MATCHING
// Returns the ID from the data table
// ============================================================================
short PropTableImpl::GetID() {
    return m_data->m_id;
}

// ============================================================================
// PropTableImpl::GetEntryName
// Address: 0x801329AC, Size: 8 bytes
// MATCHING
// Always returns NULL (names not available in release)
// ============================================================================
char* PropTableImpl::GetEntryName(int index) {
    return 0;
}

// ============================================================================
// PropTableImpl::CountEntries
// Address: 0x80132990, Size: 28 bytes
// NON_MATCHING - conditional return (beqlr) pattern
// Returns count of entries (stored at entries[-1])
// ============================================================================
int PropTableImpl::CountEntries() const {
    void** entries = m_data->m_entries;
    if (entries == 0) return 0;
    return ((int*)entries)[-1];
}
