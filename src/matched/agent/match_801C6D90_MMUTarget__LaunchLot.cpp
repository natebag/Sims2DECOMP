// 0x801C6D90 (96 bytes)
// MMUTarget::LaunchLot(int)

class MMUTarget { public: void LaunchLot(int); };

__attribute__((naked))
void MMUTarget::LaunchLot(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x2C04FFFF\n.long 0x4182000C\n.long 0x38840001\n.long 0x4800000C\n.long 0x813F0098\n.long 0x38890001\n.long 0x7FE3FB78\n.long 0x4BFFFE3D\n.long 0x38000000\n.long 0x7FE3FB78\n.long 0x901F008C\n.long 0x4BFFF9CD\n.long 0x7FE3FB78\n.long 0x4BFFFB11\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
