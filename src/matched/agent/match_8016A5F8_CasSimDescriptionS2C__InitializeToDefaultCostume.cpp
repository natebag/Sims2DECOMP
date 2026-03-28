// 0x8016A5F8 (120 bytes)
// CasSimDescriptionS2C::InitializeToDefaultCostume(bool)

class CasSimDescriptionS2C { public: void InitializeToDefaultCostume(bool); };

__attribute__((naked))
void CasSimDescriptionS2C::InitializeToDefaultCostume(bool) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9E2378\n.long 0x7C7F1B78\n.long 0x38800000\n.long 0x4BFFCD1D\n.long 0x2C1E0000\n.long 0x41820028\n.long 0x39200001\n.long 0x39600003\n.long 0x39400008\n.long 0x38000009\n.long 0x981F00CC\n.long 0x913F0084\n.long 0x997F0098\n.long 0x995F00C4\n.long 0x4800001C\n.long 0x39200004\n.long 0x38000007\n.long 0x993F00CC\n.long 0x93DF0084\n.long 0x981F00C4\n.long 0x993F0098\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
