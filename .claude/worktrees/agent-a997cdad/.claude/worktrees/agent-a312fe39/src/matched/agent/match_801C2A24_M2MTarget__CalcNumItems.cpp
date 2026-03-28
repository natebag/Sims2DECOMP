// 0x801C2A24 (80 bytes)
// M2MTarget::CalcNumItems(void)

class M2MTarget { public: void CalcNumItems(void); };

__attribute__((naked))
void M2MTarget::CalcNumItems(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F0168\n.long 0x2C000000\n.long 0x40820010\n.long 0x38000001\n.long 0x901F0188\n.long 0x48000014\n.long 0x7FE3FB78\n.long 0x389F010C\n.long 0x4BFFE671\n.long 0x907F0188\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
