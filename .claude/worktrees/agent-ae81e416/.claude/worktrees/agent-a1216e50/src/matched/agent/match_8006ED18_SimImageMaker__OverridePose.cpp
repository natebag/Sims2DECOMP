// 0x8006ED18 (96 bytes)
// SimImageMaker::OverridePose(unsigned int, EVec3 &, EVec3 &, EVec3 &, float)

class SimImageMaker { public: void OverridePose(unsigned int, EVec3 &, EVec3 &, EVec3 &, float); };

__attribute__((naked))
void SimImageMaker::OverridePose(unsigned int, EVec3 &, EVec3 &, EVec3 &, float) {
    asm volatile(".long 0x90830218\n.long 0x394301F0\n.long 0x390301FC\n.long 0x38830208\n.long 0x81650000\n.long 0x81250008\n.long 0x80050004\n.long 0x916301F0\n.long 0x912A0008\n.long 0x900A0004\n.long 0x81260000\n.long 0x80060008\n.long 0x81660004\n.long 0x912301FC\n.long 0x90080008\n.long 0x91680004\n.long 0x80070000\n.long 0x81270008\n.long 0x81670004\n.long 0x90030208\n.long 0x91240008\n.long 0x91640004\n.long 0xD0230214\n.long 0x4E800020");
}
