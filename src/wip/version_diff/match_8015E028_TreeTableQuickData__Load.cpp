// TreeTableQuickData::Load(unsigned int, short) - 0x8015E028 - 96 bytes
// STATUS: NON_MATCHING - Fundamental SN vs GCC codegen differences
//
// Known differences vs DOL:
// - Stack frame: DOL -24(r1) vs GCC -32(r1)
// - Register allocation: DOL uses r28/r30/r31 vs GCC r29/r30/r31
// - ObjectDataID call offset differs due to different store scheduling
// - Overall layout: DOL 96 bytes (24 insns) vs compiled larger
//
// The DOL appears to use SN ProDG v1.76 with different:
// - Stack frame calculation (smaller frame)
// - Register allocator (prefers r28/r30/r31 for this function)
// - Instruction scheduling for store/load pairs
//
// Workaround: Raw byte injection available at 
// src/asm_wrappers/TreeTableQuickData_rawbyte_auto.cpp

// Forward declaration only - defined in separate TU at 0x8015BAF4
struct ObjectDataID {
    unsigned int m_id;       // +0x00
    unsigned short m_type;   // +0x04
    
    ObjectDataID(unsigned int id, unsigned short type);
};

class TreeTableQuickData {
public:
    void* __vtable;      // +0x00
    char _pad[0x20];     // +0x04 to +0x23

    void LoadFromDataID(ObjectDataID& id);
    int Load(unsigned int param1, short param2);
};

// NON_MATCHING: This C++ body does not match DOL due to compiler codegen differences
// See docs/tracking/failed-matches.md for similar scheduling issues
int TreeTableQuickData::Load(unsigned int param1, short param2) {
    // ObjectDataID constructed on stack at r1+8
    ObjectDataID id(param1, (unsigned short)param2);
    
    // Virtual call to LoadFromDataID via vtable
    void** vtable = (void**)__vtable;
    short offset = *(short*)((char*)vtable + 40);  // vtable+40 = LoadFromDataID this offset
    int (*fn)(void*, ObjectDataID*) = (int (*)(void*, ObjectDataID*))vtable[11]; // vtable+44 = fn ptr
    
    int result = fn((char*)this + offset, &id);
    if (result == 0) {
        return -50;
    }
    return 0;
}
