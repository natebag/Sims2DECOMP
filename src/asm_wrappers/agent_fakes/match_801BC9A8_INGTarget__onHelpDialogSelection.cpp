// 0x801BC9A8 (104 bytes)
// INGTarget::onHelpDialogSelection(int)

class INGTarget { public: void onHelpDialogSelection(int); };

__attribute__((naked))
void INGTarget::onHelpDialogSelection(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B78\n.long 0x812B0134\n.long 0x39290001\n.long 0x28090001\n.long 0x912B0134\n.long 0x41810030\n.long 0x812B0080\n.long 0x3C80803F\n.long 0x3CA0803F\n.long 0x388416AC\n.long 0xA8690010\n.long 0x38A519F0\n.long 0x80090014\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x4800000C\n.long 0x38000000\n.long 0x900B0134\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
