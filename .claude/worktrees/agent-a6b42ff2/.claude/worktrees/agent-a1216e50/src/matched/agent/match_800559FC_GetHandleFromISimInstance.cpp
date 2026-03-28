// 0x800559FC (96 bytes)
// GetHandleFromISimInstance(ISimInstance *)

__attribute__((naked))
void GetHandleFromISimInstance(ISimInstance *) {
    asm volatile(".long 0x3D208047\n.long 0x7C6B1B78\n.long 0x81295E94\n.long 0x2C090000\n.long 0x3860FFFF\n.long 0x4D820020\n.long 0x80690004\n.long 0x2C030000\n.long 0x40820014\n.long 0x3860FFFF\n.long 0x4E800020\n.long 0x80630018\n.long 0x4E800020\n.long 0x80630004\n.long 0x2C030000\n.long 0x4182001C\n.long 0x8003001C\n.long 0x7C0B0000\n.long 0x4182FFE4\n.long 0x80630010\n.long 0x2C030000\n.long 0x4082FFEC\n.long 0x3860FFFF\n.long 0x4E800020");
}
