// 0x800B039C (100 bytes)
// cSoundModeManager::Pause(void)

class cSoundModeManager { public: void Pause(void); };

__attribute__((naked))
void cSoundModeManager::Pause(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030000\n.long 0x2C000003\n.long 0x41820040\n.long 0x816D983C\n.long 0x812B0000\n.long 0x80090054\n.long 0xA8690050\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x816D983C\n.long 0x38800001\n.long 0x812B0000\n.long 0xA8690028\n.long 0x8009002C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
