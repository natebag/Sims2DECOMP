// 0x801CFB58 (108 bytes)
// O2TTarget::OnDownKeyPressed(char *, char *)

class O2TTarget { public: void OnDownKeyPressed(char *, char *); };

__attribute__((naked))
void O2TTarget::OnDownKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030088\n.long 0x2C000000\n.long 0x40820020\n.long 0x8123009C\n.long 0x39290001\n.long 0x2C090001\n.long 0x9123009C\n.long 0x40810030\n.long 0x9003009C\n.long 0x48000028\n.long 0x2C000002\n.long 0x40820020\n.long 0x812300A0\n.long 0x39290001\n.long 0x2C090006\n.long 0x912300A0\n.long 0x4081000C\n.long 0x38000000\n.long 0x900300A0\n.long 0x4BFFF811\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
