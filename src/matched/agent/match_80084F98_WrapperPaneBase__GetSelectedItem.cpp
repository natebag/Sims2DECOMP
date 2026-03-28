// 0x80084F98 (68 bytes)
// WrapperPaneBase::GetSelectedItem(ItemType)

class WrapperPaneBase { public: void GetSelectedItem(ItemType); };

__attribute__((naked))
void WrapperPaneBase::GetSelectedItem(ItemType) {
    asm volatile(".long 0x8003000C\n.long 0x81230008\n.long 0x7C090000\n.long 0x41820030\n.long 0x7C0B0378\n.long 0x80690000\n.long 0x80030000\n.long 0x7C002000\n.long 0x40820010\n.long 0x80030004\n.long 0x700A0004\n.long 0x4C820020\n.long 0x39290004\n.long 0x7C095800\n.long 0x4082FFDC\n.long 0x38600000\n.long 0x4E800020");
}
