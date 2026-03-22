// treesim.cpp - TreeSim, TreeSimImpl, TreeStack, StackElem classes
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(treesim.obj)
//
// Small functions (<=64 bytes) decompiled from the treesim object file.
// TreeSim is the behavior tree simulation system.

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class TreeSimImpl;

// External functions
extern void EStorable_Delete(void* ptr);
extern void Stack_Initialize(void* stack, int size);

//=============================================================================
// TreeStack - stack for tree simulation
//=============================================================================
class TreeStack {
public:
    void* m_base;        // 0x00
    void* m_current;     // 0x04
    u8 m_stackData[12];  // 0x08 - embedded stack elements
    TreeSimImpl* m_impl; // 0x18

    // TreeStack constructor
    // Address: 0x80147164, Size: 52
    TreeStack(TreeSimImpl& impl) {
        *(u32*)&m_stackData[0] = 0;
        *(u32*)&m_stackData[4] = 0;
        *(u32*)&m_stackData[8] = 0;
        m_impl = &impl;
        m_current = NULL;
        m_base = NULL;
    }

    // Initialize - delegate to stack init
    // Address: 0x80147450, Size: 36
    void Initialize(int size) {
        Stack_Initialize(&m_stackData, size);
    }

    // GetMemReserved - returns used memory
    // Address: 0x80148D28, Size: 16
    int GetMemReserved() {
        return (int)m_current - (int)m_base;
    }
};

//=============================================================================
// StackElem - element on the tree stack
//=============================================================================
class StackElem {
public:
    u16 m_data;  // 0x00 - packed tree ID

    // GetTreeID
    // Address: 0x80149118, Size: 32
    int GetTreeID() const {
        u16 raw = m_data;
        if ((s16)raw == -1) return -1;
        return raw & 0x7FFF;
    }

    // SetTreeID
    // Address: 0x80149138, Size: 36
    // NON_MATCHING - bit manipulation
    void SetTreeID(short id);
};

//=============================================================================
// TreeSimImpl - implementation of tree simulation
//=============================================================================
class TreeSimImpl {
public:
    u8 pad00[0x34];
    s16 m_error;    // 0x34

    // SetError
    // Address: 0x80147434, Size: 8
    void SetError(short err) {
        m_error = err;
    }

    // GetError
    // Address: 0x8014743C, Size: 8
    short GetError() {
        return m_error;
    }

    // ClearError
    // Address: 0x80147444, Size: 12
    void ClearError() {
        m_error = 0;
    }
};

//=============================================================================
// TreeSim - base tree sim class
//=============================================================================
class TreeSim {
public:
    u8 pad00[0x18];
    void* m_vtable;  // 0x18

    // ~TreeSim
    // Address: 0x80147224, Size: 52
    // NON_MATCHING - vtable setup and conditional delete
    ~TreeSim();
};
