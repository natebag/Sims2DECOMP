// 0x8015213C (112 bytes)
// cFixedWorldImpl::MayEditTile(CTilePt &) const

class cFixedWorldImpl { public: void MayEditTile(CTilePt &) const; };

__attribute__((naked))
void cFixedWorldImpl::MayEditTile(CTilePt &) const {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x812DAC48\n.long 0x7C9F2378\n.long 0x800903DC\n.long 0x2C000000\n.long 0x40820038\n.long 0x83A30034\n.long 0x7FE3FB78\n.long 0x4BF62B41\n.long 0x7C7E1B78\n.long 0x7FE3FB78\n.long 0x4BF62B41\n.long 0x813D000C\n.long 0x57DE103A\n.long 0x7C1E482E\n.long 0x7C6300AE\n.long 0x68630020\n.long 0x5463DFFE\n.long 0x48000008\n.long 0x38600001\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
