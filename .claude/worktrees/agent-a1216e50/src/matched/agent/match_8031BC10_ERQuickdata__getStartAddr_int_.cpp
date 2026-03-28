// 0x8031BC10 (120 bytes)
// ERQuickdata::getStartAddr(int)

class ERQuickdata { public: void getStartAddr(int); };

__attribute__((naked))
void ERQuickdata::getStartAddr(int) {
    asm volatile(".long 0x1C040014\n.long 0x81630014\n.long 0x392B001C\n.long 0x7C69002E\n.long 0x2C030000\n.long 0x4C820020\n.long 0x7C802378\n.long 0x2C000000\n.long 0x3884FFFF\n.long 0x4C810020\n.long 0x1D240014\n.long 0x39290024\n.long 0x7D295A14\n.long 0x8069FFF8\n.long 0x2C030000\n.long 0x41820024\n.long 0x81690004\n.long 0x2C0B0000\n.long 0x40820008\n.long 0x39600001\n.long 0x80090000\n.long 0x7C0B01D6\n.long 0x7C630214\n.long 0x4E800020\n.long 0x7C802378\n.long 0x3929FFEC\n.long 0x2C000000\n.long 0x3884FFFF\n.long 0x4181FFC4\n.long 0x4E800020");
}
