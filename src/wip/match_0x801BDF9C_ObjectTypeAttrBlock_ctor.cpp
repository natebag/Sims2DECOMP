// 0x801BDF9C (96 bytes)
// ObjectTypeAttrBlock::ObjectTypeAttrBlock - Constructor
// Address: 0x801BDF9C | Size: 96 bytes
//
// Disassembly analysis:
// - Pattern: beq skip; load m_field_004; copy r29 to r5; call 0x80177FDC
// - Loads m_field_000 (vtable), loads string constant from 0x803F section
// - Repeats 4 times with different string constants:
//   - 0x1CC4, 0x1CD4, 0x1CE4, 0x1CF4 (approximately)
//
// Constructor calls helper function 0x80177FDC (likely InitField) 
// with different string constants for each field

class ObjectTypeAttrBlock {
public:
    void** _vtable;
    int m_field_004;
    int m_field_008;

    // Constructor stub - needs exact string constant addresses
    ObjectTypeAttrBlock(int a, int b);
};

// NON_MATCHING: String constant addresses need verification
ObjectTypeAttrBlock::ObjectTypeAttrBlock(int a, int b) {
    // The disassembly shows a pattern of conditional initialization
    // with calls to 0x80177FDC using different string constants
    m_field_004 = 0;
    m_field_008 = 0;
}
