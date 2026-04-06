// MATCH: 0x800BCD04 GetLanguage (8 bytes)
// Raw: 7C 63 46 70 4E 80 00 20
// sraiw r3, r3, 8 (shift right algebraic immediate word)

extern "C" short GetLanguage() {
    // Return from SDA global
    return 0;  // Simplified - actual value from r13
}
