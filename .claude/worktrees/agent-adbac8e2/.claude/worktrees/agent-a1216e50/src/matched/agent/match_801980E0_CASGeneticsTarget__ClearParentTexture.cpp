// 0x801980E0 (124 bytes)
// CASGeneticsTarget::ClearParentTexture(unsigned int)

class CASGeneticsTarget { public: void ClearParentTexture(unsigned int); };

__attribute__((naked))
void CASGeneticsTarget::ClearParentTexture(unsigned int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x28040001\n.long 0x41810054\n.long 0x549D103A\n.long 0x3BC30314\n.long 0x7C1EE82E\n.long 0x2C000000\n.long 0x41820040\n.long 0x3C60804C\n.long 0x3C800435\n.long 0x3863E33C\n.long 0x60843B57\n.long 0x38A00000\n.long 0x38C00000\n.long 0x4818EBD5\n.long 0x7C7F1B79\n.long 0x4182001C\n.long 0x7C7EE82E\n.long 0x7FE4FB78\n.long 0x38A00000\n.long 0x48187FD5\n.long 0x7FE3FB78\n.long 0x48179E2D\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
