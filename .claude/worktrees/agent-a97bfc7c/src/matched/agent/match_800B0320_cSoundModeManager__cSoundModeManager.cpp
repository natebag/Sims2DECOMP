// 0x800B0320 (68 bytes)
// cSoundModeManager::cSoundModeManager(void)

class cSoundModeManager { public: void cSoundModeManager(void); };

__attribute__((naked))
void cSoundModeManager::cSoundModeManager(void) {
    asm volatile(".long 0x7C691B78\n.long 0x38000000\n.long 0x39600001\n.long 0x90090030\n.long 0x9169002C\n.long 0x90090000\n.long 0x90090004\n.long 0x90090008\n.long 0x9009000C\n.long 0x90090010\n.long 0x90090014\n.long 0x90090018\n.long 0x9009001C\n.long 0x90090020\n.long 0x90090024\n.long 0x90090028\n.long 0x4E800020");
}
