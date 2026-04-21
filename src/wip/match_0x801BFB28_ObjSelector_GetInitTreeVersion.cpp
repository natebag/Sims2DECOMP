// 0x801BFB28 (104 bytes)
// ObjSelector::GetInitTreeVersion
// Address: 0x801BFB28 | Size: 104 bytes
//
// Disassembly analysis:
// - lwz r5, 400(r31) - load m_field_190
// - or r3, r30 - copy this
// - li r4, 48 - constant 48
// - bl 0x8017F884 - function call
// - lis r3, 0x803F; li r4, -1; addi r3, 3, 0x20DC
// - bl 0x80179BB0 - function call
// - cmpwi r29, 2; beq ... - switch-like pattern
// - Multiple branches based on r29 value (0, 2, 4, 7)
// - Loads from 0x80475BEC (global?)

class ObjSelector {
public:
    int m_field_190;  // at 0x190 (400)
    short m_initTreeVersion;  // at 0x00C?
    int m_field_11C;  // at 0x11C (284)
    int m_field_180;  // at 0x180 (384)

    short GetInitTreeVersion();
};

// NON_MATCHING: Switch-like pattern needs exact replication
short ObjSelector::GetInitTreeVersion() {
    // Stub - needs switch implementation
    return 0;
}
