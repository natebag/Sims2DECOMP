// 0x801DCE2C (76 bytes)
// R2LTarget::onSummaryDialogSelection(int)

class R2LTarget { public: void onSummaryDialogSelection(int); };

__attribute__((naked))
void R2LTarget::onSummaryDialogSelection(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x38000000\n.long 0x2C040000\n.long 0x900300B8\n.long 0x40820024\n.long 0x3CA0803F\n.long 0x80830094\n.long 0x38C30084\n.long 0x38A550BC\n.long 0x38630144\n.long 0x38E00000\n.long 0x39000000\n.long 0x4BF99079\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
