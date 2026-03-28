// 0x80152080 (84 bytes)
// cFixedWorldImpl::GetWallStorage(CTilePt &)

class cFixedWorldImpl { public: void GetWallStorage(CTilePt &); };

__attribute__((naked))
void cFixedWorldImpl::GetWallStorage(CTilePt &) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7C9D2378\n.long 0x83830038\n.long 0x7FA3EB78\n.long 0x4BF62C0D\n.long 0x7C7E1B78\n.long 0x7FA3EB78\n.long 0x4BF62C0D\n.long 0x813C000C\n.long 0x54601838\n.long 0x57DE103A\n.long 0x7C7E482E\n.long 0x7C630214\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
