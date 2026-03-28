#ifndef PROPTABLE_H
#define PROPTABLE_H

#include "types.h"

// Forward declarations
struct PropRefTable;

// ============================================================================
// PropTable - Abstract property table interface
// Object file: proptable.obj
//
// Layout:
//   +0x00: vtable* (PropTable virtual table at 0x80464140)
// ============================================================================
class PropTable {
public:
    virtual ~PropTable();

    static PropTable* CreateInstance();
    static void DestroyInstance(PropTable* table);
};

// ============================================================================
// PropTableImpl - Concrete property table implementation
// Object file: proptable.obj
//
// Layout (from disassembly):
//   +0x00: vtable* (PropTableImpl virtual table at 0x80464100)
//   +0x04: PropRefTable* m_data
// ============================================================================
class PropTableImpl : public PropTable {
public:
    PropRefTable* m_data;   // +0x04

    PropTableImpl();
    virtual ~PropTableImpl();

    void Load(unsigned int id, short param);
    void* GetEntry(int index);
    short GetID();
    int CountEntries() const;
    char* GetEntryName(int index);
};

// ============================================================================
// PropRefTable - Raw property reference table data
// Layout (from disassembly):
//   +0x00: void** m_entries (pointer to array, count at entries[-1])
//   +0x04: s16 m_id
// ============================================================================
struct PropRefTable {
    void** m_entries;   // +0x00
    s16    m_id;        // +0x04
};

// Template function from proptable.obj
template<class T>
T* FindRes(T* begin, T* end, int id);

#endif // PROPTABLE_H
