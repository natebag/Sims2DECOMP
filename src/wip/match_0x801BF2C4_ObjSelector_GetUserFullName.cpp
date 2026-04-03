// ObjSelector::GetUserFullName
// Address: 0x801BF2C4 | Size: 108 bytes
//
// Disassembly analysis:
// - b 0x801BF2CC - branch to main code (skip data?)
// - stw r31, 8(r1) - stack stores
// - stw r29, 20(r1)
// - lis r9, 0x803F; lwz r5, 8(r1)
// - addi r9, r9, 0x1F28
// - Loads from r22: 4(r22), 8(r22), 0xC(r22)
// - addi r11, r31, 0x28
// - Stores to r11 (r31+0x28): r6 at +4, r10 at +8, r0 at +0xC
// - lis r9, 0x803C; addi r29, r9, -0x7F6C
// - Stores r31 at 16(r1)
// - Conditional branch based on comparison
// - or r4, r18; or r3, r22; li r5, 8

class BString2;

class ObjSelector {
public:
    int m_field_28;   // at 0x28 (40) - BString storage?
    int m_userName;   // at 0x084
    int m_userLastName; // at 0x088

    void GetUserFullName(BString2& out);
};

// NON_MATCHING: Complex string concatenation logic
void ObjSelector::GetUserFullName(BString2& out) {
    // Stub - concatenates userName + userLastName
}
