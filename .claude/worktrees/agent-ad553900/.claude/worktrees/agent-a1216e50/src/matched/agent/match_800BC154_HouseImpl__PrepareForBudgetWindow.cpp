// 0x800BC154 (100 bytes)
// HouseImpl::PrepareForBudgetWindow(void)

class HouseImpl { public: void PrepareForBudgetWindow(void); };

__attribute__((naked))
void HouseImpl::PrepareForBudgetWindow(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x812DAC08\n.long 0x7C7F1B78\n.long 0x81690000\n.long 0xA86B0080\n.long 0x800B0084\n.long 0x7C691A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C030001\n.long 0x4182001C\n.long 0x813F0000\n.long 0xA8690088\n.long 0x8009008C\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
