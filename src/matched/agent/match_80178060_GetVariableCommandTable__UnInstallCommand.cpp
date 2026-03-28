// 0x80178060 (120 bytes)
// GetVariableCommandTable::UnInstallCommand(char *)

class GetVariableCommandTable { public: void UnInstallCommand(char *); };

__attribute__((naked))
void GetVariableCommandTable::UnInstallCommand(char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7D1B78\n.long 0x7C9E2378\n.long 0x83FD0000\n.long 0x2C1F0000\n.long 0x41820040\n.long 0x807F0008\n.long 0x7C03F000\n.long 0x41820014\n.long 0x7FC4F378\n.long 0x480CB7A5\n.long 0x2C030000\n.long 0x40820018\n.long 0x7FA3EB78\n.long 0x7FE4FB78\n.long 0x4BFFFEA5\n.long 0x38600001\n.long 0x48000014\n.long 0x83FF0004\n.long 0x2C1F0000\n.long 0x4082FFC8\n.long 0x38600000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
