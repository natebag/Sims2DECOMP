// 0x80085034 (72 bytes)
// WrapperPaneBase::GetItem(ItemType, int)

class WrapperPaneBase { public: void GetItem(ItemType, int); };

__attribute__((naked))
void WrapperPaneBase::GetItem(ItemType, int) {
    asm volatile(".long 0x8003000C\n.long 0x39600000\n.long 0x81230008\n.long 0x7C090000\n.long 0x41820030\n.long 0x7C0A0378\n.long 0x80690000\n.long 0x80030000\n.long 0x7C002000\n.long 0x40820010\n.long 0x7C0B2800\n.long 0x4D820020\n.long 0x396B0001\n.long 0x39290004\n.long 0x7C095000\n.long 0x4082FFDC\n.long 0x38600000\n.long 0x4E800020");
}
