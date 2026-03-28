// 0x801ACEA4 (68 bytes)
// E2ETarget::OnExitDialog(int)

class E2ETarget { public: void OnExitDialog(int); };

__attribute__((naked))
void E2ETarget::OnExitDialog(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x48000039\n.long 0x2C030000\n.long 0x40820020\n.long 0x3C60803F\n.long 0x38800000\n.long 0x3863F860\n.long 0x38A00000\n.long 0x38C00000\n.long 0x38E00000\n.long 0x4BFCAE81\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
