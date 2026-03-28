// 0x801B5960 (96 bytes)
// G2DTarget::HideDialog(void)

class G2DTarget { public: void HideDialog(void); };

__attribute__((naked))
void G2DTarget::HideDialog(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030134\n.long 0x2C000003\n.long 0x41820018\n.long 0x3C60803F\n.long 0x38630CFC\n.long 0x4CC63182\n.long 0x48201A1D\n.long 0x48000028\n.long 0x800300C4\n.long 0x2C000000\n.long 0x40820008\n.long 0x90030118\n.long 0x39200000\n.long 0x38000004\n.long 0x90030134\n.long 0x91230114\n.long 0x91230110\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
