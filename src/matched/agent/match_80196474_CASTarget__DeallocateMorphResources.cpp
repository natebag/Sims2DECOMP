// 0x80196474 (72 bytes)
// CASTarget::DeallocateMorphResources(int)

class CASTarget { public: void DeallocateMorphResources(int); };

__attribute__((naked))
void CASTarget::DeallocateMorphResources(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x28040003\n.long 0x41810028\n.long 0x54801838\n.long 0x7C002214\n.long 0x54003032\n.long 0x7D201A14\n.long 0x2C09F5B0\n.long 0x41820010\n.long 0x7D234B78\n.long 0x38630A50\n.long 0x4BEDA44D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
