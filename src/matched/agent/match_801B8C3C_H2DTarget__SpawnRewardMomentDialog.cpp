// 0x801B8C3C (92 bytes)
// H2DTarget::SpawnRewardMomentDialog(int, int)

class H2DTarget { public: void SpawnRewardMomentDialog(int, int); };

__attribute__((naked))
void H2DTarget::SpawnRewardMomentDialog(int, int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C691B78\n.long 0x800900CC\n.long 0x2C000000\n.long 0x40820010\n.long 0x800900DC\n.long 0x2C000000\n.long 0x4182000C\n.long 0x38600000\n.long 0x48000020\n.long 0x38000001\n.long 0x38600000\n.long 0x90A900D8\n.long 0x900900DC\n.long 0x908900D4\n.long 0x4BFFFDC1\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
