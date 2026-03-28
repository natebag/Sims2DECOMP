// 0x801AE838 (84 bytes)
// E2ETarget::OnSaveGameDialogClosed(int)

class E2ETarget { public: void OnSaveGameDialogClosed(int); };

__attribute__((naked))
void E2ETarget::OnSaveGameDialogClosed(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C691B78\n.long 0x2C040000\n.long 0x4082000C\n.long 0x4BFFE161\n.long 0x48000028\n.long 0x38000000\n.long 0x3C60803F\n.long 0x900900E0\n.long 0x3863F72C\n.long 0x38800000\n.long 0x38A00000\n.long 0x38C00000\n.long 0x38E00000\n.long 0x4BFC94DD\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
