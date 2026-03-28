// 0x801C781C (80 bytes)
// MMUTarget::OnCircleKeyPressed(char *, char *)

class MMUTarget { public: void OnCircleKeyPressed(char *, char *); };

__attribute__((naked))
void MMUTarget::OnCircleKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F008C\n.long 0x2C000000\n.long 0x40820020\n.long 0x3D208047\n.long 0x800961D0\n.long 0x2C000000\n.long 0x41820010\n.long 0x4BFFEE41\n.long 0x7FE3FB78\n.long 0x48000145\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
