// 0x8018FF3C (80 bytes)
// SaveGameTarget::BGExec_SaveGame(void *)

class SaveGameTarget { public: void BGExec_SaveGame(void *); };

__attribute__((naked))
void SaveGameTarget::BGExec_SaveGame(void *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B79\n.long 0x41820020\n.long 0x807F0128\n.long 0x3CC000AB\n.long 0x38800001\n.long 0x38A00000\n.long 0x60C6CDEF\n.long 0x4BEE5955\n.long 0x907F013C\n.long 0x38000001\n.long 0x900DAC18\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
