// 0x801AE598 (72 bytes)
// E2ETarget::OnSaveGameComplete(bool)

class E2ETarget { public: void OnSaveGameComplete(bool); };

__attribute__((naked))
void E2ETarget::OnSaveGameComplete(bool) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C691B78\n.long 0x38000000\n.long 0x3C60803F\n.long 0x90090284\n.long 0x3863F72C\n.long 0x900900E0\n.long 0x38800000\n.long 0x38A00000\n.long 0x38C00000\n.long 0x38E00000\n.long 0x4BFC9789\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
