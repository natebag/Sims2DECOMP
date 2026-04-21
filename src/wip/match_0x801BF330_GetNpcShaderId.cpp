// 0x801BF330 (96 bytes)
// GetNpcShaderId - NPC shader lookup utility
// Address: 0x801BF330 | Size: 96 bytes
//
// Disassembly analysis:
// - Calls 0x80243454 first
// - Stores r31 at 8(r1), r29 at 20(r1)
// - Loads from r9 (lis 0x803F) + offset 0x1F30
// - Loads from r22+4, r22+8, r22+0xC
// - Stores to r31+0x38 and other offsets
// - Complex stack manipulation

// This appears to copy shader data from one structure to another

// NON_MATCHING: Complex stack/register usage needs verification
struct NpcShaderInfo {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

void GetNpcShaderId(void* src, void* dst) {
    // Stub - needs exact field offsets and copy semantics
}
