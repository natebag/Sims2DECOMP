// 0x8018204C (116 bytes)
// UIUserDrawCBTable::InstallEntry(char *, CBFunctor2<ERC *, structDrawCBparams *> *, char *)

class UIUserDrawCBTable { public: void InstallEntry(char *, CBFunctor2<ERC *, structDrawCBparams *> *, char *); };

__attribute__((naked))
void UIUserDrawCBTable::InstallEntry(char *, CBFunctor2<ERC *, structDrawCBparams *> *, char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7C7F1B78\n.long 0x7C9D2378\n.long 0x801F0008\n.long 0x7CBE2B78\n.long 0x7CDC3378\n.long 0x2C000000\n.long 0x4182002C\n.long 0x480000FD\n.long 0x2C030000\n.long 0x40820020\n.long 0x7FE3FB78\n.long 0x7FA4EB78\n.long 0x7FC5F378\n.long 0x7F86E378\n.long 0x4BFFFE85\n.long 0x38600001\n.long 0x48000010\n.long 0x7FC3F378\n.long 0x4814F17D\n.long 0x38600000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
