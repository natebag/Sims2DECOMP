// 0x80152018 (104 bytes)
// cFixedWorldImpl::HasWalls(CTilePt &)

class cFixedWorldImpl { public: void HasWalls(CTilePt &); };

__attribute__((naked))
void cFixedWorldImpl::HasWalls(CTilePt &) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7C9D2378\n.long 0x83830038\n.long 0x7FA3EB78\n.long 0x4BF62C75\n.long 0x7C7E1B78\n.long 0x7FA3EB78\n.long 0x4BF62C75\n.long 0x817C000C\n.long 0x57DE103A\n.long 0x54631838\n.long 0x39400001\n.long 0x7D3E582E\n.long 0x7C0918AE\n.long 0x2C000000\n.long 0x40820008\n.long 0x39400000\n.long 0x7D435378\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
