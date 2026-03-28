// 0x801CEAC0 (108 bytes)
// O2TTarget::Shutdown(char *, char *)

class O2TTarget { public: void Shutdown(char *, char *); };

__attribute__((naked))
void O2TTarget::Shutdown(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030090\n.long 0x2C000000\n.long 0x40820048\n.long 0x80030248\n.long 0x2C000000\n.long 0x4082003C\n.long 0x38000001\n.long 0x3D208047\n.long 0x90030254\n.long 0x3C80803F\n.long 0x3CA0803F\n.long 0x3884EB18\n.long 0x81695EF8\n.long 0x38A5EB24\n.long 0x812B0080\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
