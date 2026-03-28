// 0x801CFBC4 (124 bytes)
// O2TTarget::OnRightKeyPressed(char *, char *)

class O2TTarget { public: void OnRightKeyPressed(char *, char *); };

__attribute__((naked))
void O2TTarget::OnRightKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030088\n.long 0x2C000000\n.long 0x41820058\n.long 0x2C000002\n.long 0x4082004C\n.long 0x800300A0\n.long 0x2C000003\n.long 0x40820020\n.long 0x892D8BD5\n.long 0x7D200774\n.long 0x2C000009\n.long 0x41810030\n.long 0x38090001\n.long 0x980D8BD5\n.long 0x48000024\n.long 0x2C000004\n.long 0x4082001C\n.long 0x892D8BD4\n.long 0x7D200774\n.long 0x2C000009\n.long 0x4181000C\n.long 0x38090001\n.long 0x980D8BD4\n.long 0x4BFFF4C1\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
