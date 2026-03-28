// 0x801635E8 (96 bytes)
// CasNpcEditor::SaveSim(void)

class CasNpcEditor { public: void SaveSim(void); };

__attribute__((naked))
void CasNpcEditor::SaveSim(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030008\n.long 0x2C000002\n.long 0x41820028\n.long 0x41810010\n.long 0x2C000001\n.long 0x41820014\n.long 0x48000028\n.long 0x2C000003\n.long 0x41820018\n.long 0x4800001C\n.long 0x4800002D\n.long 0x48000018\n.long 0x48000C41\n.long 0x48000010\n.long 0x480017C1\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
