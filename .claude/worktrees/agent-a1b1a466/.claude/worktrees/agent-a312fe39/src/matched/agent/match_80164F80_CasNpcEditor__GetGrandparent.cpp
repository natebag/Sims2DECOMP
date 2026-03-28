// 0x80164F80 (92 bytes)
// CasNpcEditor::GetGrandparent(unsigned int)

class CasNpcEditor { public: void GetGrandparent(unsigned int); };

__attribute__((naked))
void CasNpcEditor::GetGrandparent(unsigned int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x28040033\n.long 0x41810038\n.long 0x7C852378\n.long 0x38800001\n.long 0x28050019\n.long 0x4081000C\n.long 0x38A5FFE6\n.long 0x38800000\n.long 0x80630058\n.long 0x4BFFC84D\n.long 0x7C631B79\n.long 0x41820010\n.long 0x80630000\n.long 0x2C030000\n.long 0x40820008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
