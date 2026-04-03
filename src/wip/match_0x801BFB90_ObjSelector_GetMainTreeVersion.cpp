// ObjSelector::GetMainTreeVersion
// Address: 0x801BFB90 | Size: 104 bytes
//
// Disassembly analysis:
// - or r3, r31 - copy this
// - bl 0x801C1EC4 - function call
// - b to exit block (0x801BFC78)
// - li r0, 0; li r9, 1
// - stw r0, 284(r31); stw r9, 384(r31) - set fields
// - Multiple code blocks setting different values:
//   - Block 1: r0=0, r9=1, stores to 0x11C and 0x180
//   - Block 2: r0=15, r9=1
//   - Block 3: r0=11, call 0x801C1540
// - Switch-like pattern with fall-through

class ObjSelector {
public:
    int m_field_11C;   // at 0x11C (284)
    int m_field_168;   // at 0x168 (360)  
    int m_field_180;   // at 0x180 (384)

    short GetMainTreeVersion();
};

// NON_MATCHING: Multiple branches, switch pattern
short ObjSelector::GetMainTreeVersion() {
    // Stub - needs switch implementation
    return 0;
}
