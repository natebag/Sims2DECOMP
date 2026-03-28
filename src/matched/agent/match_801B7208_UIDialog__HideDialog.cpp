// 0x801B7208 (116 bytes)
// UIDialog::HideDialog(void)

class UIDialog { public: void HideDialog(void); };

__attribute__((naked))
void UIDialog::HideDialog(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38800000\n.long 0x38A0FFFF\n.long 0x387E0028\n.long 0x4BEEB7C1\n.long 0x38800000\n.long 0x38A0FFFF\n.long 0x387E0030\n.long 0x4BEEB7B1\n.long 0x38800000\n.long 0x38A0FFFF\n.long 0x387E0034\n.long 0x4BEEB7A1\n.long 0x387E0038\n.long 0x38800000\n.long 0x38A0FFFF\n.long 0x4BEEB791\n.long 0x3D208047\n.long 0x80695F08\n.long 0x4BFFE6FD\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
