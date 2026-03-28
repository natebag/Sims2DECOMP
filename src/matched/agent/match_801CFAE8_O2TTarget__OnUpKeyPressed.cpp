// 0x801CFAE8 (112 bytes)
// O2TTarget::OnUpKeyPressed(char *, char *)

class O2TTarget { public: void OnUpKeyPressed(char *, char *); };

__attribute__((naked))
void O2TTarget::OnUpKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030088\n.long 0x2C000000\n.long 0x40820024\n.long 0x8123009C\n.long 0x3929FFFF\n.long 0x2C090000\n.long 0x9123009C\n.long 0x40800034\n.long 0x38000001\n.long 0x9003009C\n.long 0x48000028\n.long 0x2C000002\n.long 0x40820020\n.long 0x812300A0\n.long 0x3929FFFF\n.long 0x2C090000\n.long 0x912300A0\n.long 0x4080000C\n.long 0x38000006\n.long 0x900300A0\n.long 0x4BFFF87D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
