// 0x80175F68 (72 bytes)
// HelpDialog::SelectionCallback(int)

class HelpDialog { public: void SelectionCallback(int); };

__attribute__((naked))
void HelpDialog::SelectionCallback(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x8163008C\n.long 0x38000000\n.long 0x90030088\n.long 0x2C0B0000\n.long 0x4182001C\n.long 0x812B0000\n.long 0xA8690008\n.long 0x8009000C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
