// 0x80084FDC (88 bytes)
// WrapperPaneBase::GetEnabledItemIndexWithValue(ItemType, int)

class WrapperPaneBase { public: void GetEnabledItemIndexWithValue(ItemType, int); };

__attribute__((naked))
void WrapperPaneBase::GetEnabledItemIndexWithValue(ItemType, int) {
    asm volatile(".long 0x8003000C\n.long 0x81630008\n.long 0x38600000\n.long 0x7C0B0000\n.long 0x41820040\n.long 0x7C0A0378\n.long 0x812B0000\n.long 0x80090000\n.long 0x7C002000\n.long 0x40820020\n.long 0x80090004\n.long 0x70080001\n.long 0x41820014\n.long 0x80090008\n.long 0x7C002800\n.long 0x4D820020\n.long 0x38630001\n.long 0x396B0004\n.long 0x7C0B5000\n.long 0x4082FFCC\n.long 0x3860FFFF\n.long 0x4E800020");
}
