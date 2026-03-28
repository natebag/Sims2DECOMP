// 0x800882C8 (64 bytes)
// WrapperPaneBase::GetButtonPos(WrapperPaneBase::ButtonType) const

class WrapperPaneBase { public: void GetButtonPos(WrapperPaneBase::ButtonType) const; };

__attribute__((naked))
void WrapperPaneBase::GetButtonPos(WrapperPaneBase::ButtonType) const {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x38630040\n.long 0x5484103A\n.long 0x7D63202E\n.long 0x812B001C\n.long 0xA8690040\n.long 0x80090044\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
