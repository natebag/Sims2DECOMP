// 0x801AD618 (68 bytes)
// E2ETarget::ChangeFunFrame(char *, char *)

class E2ETarget { public: void ChangeFunFrame(char *, char *); };

__attribute__((naked))
void E2ETarget::ChangeFunFrame(char *, char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7CA32B78\n.long 0x48131621\n.long 0x2C030063\n.long 0x40820008\n.long 0x3860FFFF\n.long 0x907F00BC\n.long 0x4BE8B80D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
