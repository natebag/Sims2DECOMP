// 0x801FF7BC (124 bytes)
// PSETarget::SetVariable(char *, char *)

class PSETarget { public: void SetVariable(char *, char *); };

__attribute__((naked))
void PSETarget::SetVariable(char *, char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x3C608040\n.long 0x7CBF2B78\n.long 0x3863B348\n.long 0x48044061\n.long 0x2C030000\n.long 0x40820044\n.long 0x7FE3FB78\n.long 0x480DF469\n.long 0x2C030002\n.long 0x41820024\n.long 0x41810030\n.long 0x2C030001\n.long 0x40820028\n.long 0x3C608040\n.long 0x38800001\n.long 0x3863B3B0\n.long 0x4BF7A3A5\n.long 0x48000014\n.long 0x3C608040\n.long 0x38800006\n.long 0x3863B3B0\n.long 0x4BF7A391\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
