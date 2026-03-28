// 0x80084F30 (104 bytes)
// WrapperPaneBase::SetSelected(ItemType, int)

class WrapperPaneBase { public: void SetSelected(ItemType, int); };

__attribute__((naked))
void WrapperPaneBase::SetSelected(ItemType, int) {
    asm volatile(".long 0x39230008\n.long 0x81430008\n.long 0x80090004\n.long 0x39000000\n.long 0x7C0A0000\n.long 0x4D820020\n.long 0x7D234B78\n.long 0x812A0000\n.long 0x80090000\n.long 0x7C002000\n.long 0x4082002C\n.long 0x80090004\n.long 0x540B07B8\n.long 0x70070001\n.long 0x91690004\n.long 0x41820018\n.long 0x7C082800\n.long 0x4082000C\n.long 0x61600004\n.long 0x90090004\n.long 0x39080001\n.long 0x80030004\n.long 0x394A0004\n.long 0x7C0A0000\n.long 0x4082FFBC\n.long 0x4E800020");
}
