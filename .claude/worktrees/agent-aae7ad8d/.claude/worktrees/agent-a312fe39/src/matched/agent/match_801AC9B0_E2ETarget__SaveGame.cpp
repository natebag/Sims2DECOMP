// 0x801AC9B0 (92 bytes)
// E2ETarget::SaveGame(void)

class E2ETarget { public: void SaveGame(void); };

__attribute__((naked))
void E2ETarget::SaveGame(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x38000001\n.long 0x3D20803F\n.long 0x900300E0\n.long 0x38800000\n.long 0x3869F7FC\n.long 0x38A00000\n.long 0x38C00000\n.long 0x38E00000\n.long 0x4BFCB379\n.long 0x3C60803F\n.long 0x38800003\n.long 0x3863F810\n.long 0x4BFCD1C5\n.long 0x3C60803F\n.long 0x3863F81C\n.long 0x4BFCB315\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
