// 0x801C85D0 (76 bytes)
// MMUTarget::UpdateDevMenuState(char *, char *)

class MMUTarget { public: void UpdateDevMenuState(char *, char *); };

__attribute__((naked))
void MMUTarget::UpdateDevMenuState(char *, char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x3D208047\n.long 0x7C7F1B78\n.long 0x800961D0\n.long 0x7CA32B78\n.long 0x2C000000\n.long 0x41820014\n.long 0x48116659\n.long 0x7C641B78\n.long 0x7FE3FB78\n.long 0x480000B1\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
