// 0x80089EB0 (124 bytes)
// InLevelBaseState::Shutdown(void)

class InLevelBaseState { public: void Shutdown(void); };

__attribute__((naked))
void InLevelBaseState::Shutdown(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x3D208047\n.long 0x3D608048\n.long 0x3BC95B84\n.long 0x396B58D8\n.long 0x815E0044\n.long 0x3BE00000\n.long 0x38000001\n.long 0x93EB0028\n.long 0x900B0034\n.long 0x2C0A0000\n.long 0x93EB002C\n.long 0x900B0030\n.long 0x41820024\n.long 0x812A0080\n.long 0x38800003\n.long 0xA8690008\n.long 0x8009000C\n.long 0x7C6A1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x93FE0044\n.long 0x93FE008C\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
