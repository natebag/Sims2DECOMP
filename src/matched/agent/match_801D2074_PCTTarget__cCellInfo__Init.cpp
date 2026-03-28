// 0x801D2074 (68 bytes)
// PCTTarget::cCellInfo::Init(int, FenceData *)

class PCTTarget { public: void cCellInfo::Init(int, FenceData *); };

__attribute__((naked))
void PCTTarget::cCellInfo::Init(int, FenceData *) {
    asm volatile(".long 0x7CA52B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x38000002\n.long 0x90830004\n.long 0x90030000\n.long 0x90A30014\n.long 0x80050000\n.long 0x2C000000\n.long 0x90030008\n.long 0x40820010\n.long 0x3C00D59C\n.long 0x60007BB5\n.long 0x90030008\n.long 0x38600001\n.long 0x4E800020");
}
