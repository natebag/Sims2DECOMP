// 0x800452A4 (68 bytes)
// HouseRecon::findHRSelector(int)

class HouseRecon { public: void findHRSelector(int); };

__attribute__((naked))
void HouseRecon::findHRSelector(int) {
    asm volatile(".long 0x3C630001\n.long 0x39200000\n.long 0x81636004\n.long 0x7C095800\n.long 0x4080002C\n.long 0x38638004\n.long 0x80030000\n.long 0x3863001C\n.long 0x7C002000\n.long 0x4082000C\n.long 0x7D234B78\n.long 0x4E800020\n.long 0x39290001\n.long 0x7C095800\n.long 0x4180FFE0\n.long 0x3860FFFF\n.long 0x4E800020");
}
