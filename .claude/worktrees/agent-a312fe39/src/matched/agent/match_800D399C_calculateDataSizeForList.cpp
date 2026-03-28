// 0x800D399C (72 bytes)
// calculateDataSizeForList(NghResFileWriteInfo *, int &)

__attribute__((naked))
void calculateDataSizeForList(NghResFileWriteInfo *, int &) {
    asm volatile(".long 0x39600000\n.long 0x39400000\n.long 0x7C631B79\n.long 0x41820030\n.long 0x81230004\n.long 0x2C090000\n.long 0x41820018\n.long 0x380B0003\n.long 0x81290000\n.long 0x540B003A\n.long 0x394A0001\n.long 0x7D6B4A14\n.long 0x80630000\n.long 0x2C030000\n.long 0x4082FFD8\n.long 0x91440000\n.long 0x7D635B78\n.long 0x4E800020");
}
