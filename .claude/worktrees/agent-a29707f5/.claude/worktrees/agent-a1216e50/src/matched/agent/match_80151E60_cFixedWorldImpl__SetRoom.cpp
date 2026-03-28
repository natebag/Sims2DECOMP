// 0x80151E60 (88 bytes)
// cFixedWorldImpl::SetRoom(CTilePt &, unsigned short)

class cFixedWorldImpl { public: void SetRoom(CTilePt &, unsigned short); };

__attribute__((naked))
void cFixedWorldImpl::SetRoom(CTilePt &, unsigned short) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBF61000C\n.long 0x90010024\n.long 0x7C9D2378\n.long 0x83830030\n.long 0x7CBB2B78\n.long 0x7FA3EB78\n.long 0x4BF62E29\n.long 0x7C7E1B78\n.long 0x7FA3EB78\n.long 0x4BF62E29\n.long 0x817C000C\n.long 0x57DE103A\n.long 0x5463083C\n.long 0x7D3E582E\n.long 0x7F691B2E\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBB61000C\n.long 0x38210020\n.long 0x4E800020");
}
