// 0x80164FDC (80 bytes)
// CasNpcEditor::GetCostume(unsigned int)

class CasNpcEditor { public: void GetCostume(unsigned int); };

__attribute__((naked))
void CasNpcEditor::GetCostume(unsigned int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x280400A1\n.long 0x4181002C\n.long 0x7C852378\n.long 0x38800001\n.long 0x28050050\n.long 0x4081000C\n.long 0x38A5FFAF\n.long 0x38800000\n.long 0x3D208047\n.long 0x8069625C\n.long 0x4BFFB0FD\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
