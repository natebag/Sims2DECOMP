// 0x8000FD38 (108 bytes)
// AptParagraph::SetFormattingEnable(int)

class AptParagraph { public: void SetFormattingEnable(int); };

__attribute__((naked))
void AptParagraph::SetFormattingEnable(int) {
    asm volatile(".long 0x80630000\n.long 0x2C030000\n.long 0x4D820020\n.long 0x81630004\n.long 0x2C0B0000\n.long 0x41820048\n.long 0x4F000000\n.long 0x2F840000\n.long 0x812B000C\n.long 0x2C090000\n.long 0x41820014\n.long 0x38000001\n.long 0x409E0008\n.long 0x38000000\n.long 0x90090020\n.long 0x812B0010\n.long 0x2C090000\n.long 0x41820014\n.long 0x38000001\n.long 0x409E0008\n.long 0x38000000\n.long 0x90090020\n.long 0x409AFFC8\n.long 0x80630000\n.long 0x2C030000\n.long 0x4082FFA8\n.long 0x4E800020");
}
