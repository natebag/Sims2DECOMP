// 0x801B59C0 (68 bytes)
// G2DTarget::HideDialogRunCallbacks(void)

class G2DTarget { public: void HideDialogRunCallbacks(void); };

__attribute__((naked))
void G2DTarget::HideDialogRunCallbacks(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030134\n.long 0x2C000003\n.long 0x41820018\n.long 0x3C60803F\n.long 0x38630D3C\n.long 0x4CC63182\n.long 0x482019BD\n.long 0x4800000C\n.long 0x38000004\n.long 0x90030134\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
