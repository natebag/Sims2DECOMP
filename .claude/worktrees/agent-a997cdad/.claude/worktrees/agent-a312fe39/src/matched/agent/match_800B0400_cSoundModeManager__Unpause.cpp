// 0x800B0400 (88 bytes)
// cSoundModeManager::Unpause(void)

class cSoundModeManager { public: void Unpause(void); };

__attribute__((naked))
void cSoundModeManager::Unpause(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816D983C\n.long 0x812B0000\n.long 0x8009005C\n.long 0xA8690058\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x816D983C\n.long 0x38800001\n.long 0x812B0000\n.long 0xA8690028\n.long 0x8009002C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
