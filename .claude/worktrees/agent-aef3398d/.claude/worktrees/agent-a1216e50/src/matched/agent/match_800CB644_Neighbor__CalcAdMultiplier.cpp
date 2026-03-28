// 0x800CB644 (100 bytes)
// Neighbor::CalcAdMultiplier(float, float, float)

class Neighbor { public: void CalcAdMultiplier(float, float, float); };

__attribute__((naked))
void Neighbor::CalcAdMultiplier(float, float, float) {
    asm volatile(".long 0x3D20803E\n.long 0xFC001090\n.long 0xC1A9A6E0\n.long 0x38000000\n.long 0xFC021800\n.long 0x40810010\n.long 0xFC401890\n.long 0x38000001\n.long 0xFC600090\n.long 0xFC011000\n.long 0x40810020\n.long 0x3D20803E\n.long 0xFC011800\n.long 0xC1A9A6E4\n.long 0x40800010\n.long 0xEDA31028\n.long 0xEC011028\n.long 0xEDA06824\n.long 0x2C000000\n.long 0x41820010\n.long 0x3D20803E\n.long 0xC009A6E4\n.long 0xEDA06828\n.long 0xFC206890\n.long 0x4E800020");
}
