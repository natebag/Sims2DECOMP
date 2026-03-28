// 0x80151F08 (84 bytes)
// cFixedWorldImpl::SetFlags(CTilePt &, unsigned char)

class cFixedWorldImpl { public: void SetFlags(CTilePt &, unsigned char); };

__attribute__((naked))
void cFixedWorldImpl::SetFlags(CTilePt &, unsigned char) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBF61000C\n.long 0x90010024\n.long 0x7C9D2378\n.long 0x83830034\n.long 0x7CBB2B78\n.long 0x7FA3EB78\n.long 0x4BF62D81\n.long 0x7C7E1B78\n.long 0x7FA3EB78\n.long 0x4BF62D81\n.long 0x813C000C\n.long 0x57DE103A\n.long 0x7C1E482E\n.long 0x7F6301AE\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBB61000C\n.long 0x38210020\n.long 0x4E800020");
}
