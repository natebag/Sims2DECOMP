// 0x80132D3C (96 bytes)
// SetReconDumpFile(char *)

__attribute__((naked))
void SetReconDumpFile(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x800D843C\n.long 0x7C7F1B78\n.long 0x2C000000\n.long 0x41820014\n.long 0x7C030378\n.long 0x481A47D5\n.long 0x38000000\n.long 0x900D843C\n.long 0x2C1F0000\n.long 0x41820018\n.long 0x3C80803E\n.long 0x7FE3FB78\n.long 0x3884D04C\n.long 0x481A4769\n.long 0x906D843C\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
