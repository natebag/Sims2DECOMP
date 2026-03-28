// 0x8017859C (96 bytes)
// SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)

class SetVariableCommandTable { public: void UnInstallAllCommands(CBFunctor2<char *, char *> &); };

__attribute__((naked))
void SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x7C9D2378\n.long 0x809E0000\n.long 0x38600000\n.long 0x2C040000\n.long 0x41820028\n.long 0x8004000C\n.long 0x83E40004\n.long 0x7C00E800\n.long 0x40820010\n.long 0x7FC3F378\n.long 0x4BFFFE39\n.long 0x38600001\n.long 0x7FE4FB79\n.long 0x4082FFE0\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
