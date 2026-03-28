// 0x80187E3C (120 bytes)
// HUDTarget::ShowHUD(void)

class HUDTarget { public: void ShowHUD(void); };

__attribute__((naked))
void HUDTarget::ShowHUD(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x807F00EC\n.long 0x4BFFDAA9\n.long 0x70600001\n.long 0x40820044\n.long 0x801F00E4\n.long 0x2C000000\n.long 0x41820038\n.long 0x7FE3FB78\n.long 0x4800073D\n.long 0x881F00E8\n.long 0x2C000000\n.long 0x40820024\n.long 0x3C80803F\n.long 0x806D9DD0\n.long 0x3884B340\n.long 0x38A00000\n.long 0x38C00000\n.long 0x38E00000\n.long 0x4CC63182\n.long 0x4BE884F9\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
