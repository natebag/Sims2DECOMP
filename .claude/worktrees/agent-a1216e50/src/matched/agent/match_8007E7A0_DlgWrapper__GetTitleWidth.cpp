// 0x8007E7A0 (64 bytes)
// DlgWrapper::GetTitleWidth(void) const

class DlgWrapper { public: void GetTitleWidth(void) const; };

__attribute__((naked))
void DlgWrapper::GetTitleWidth(void) const {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x812300AC\n.long 0x81490060\n.long 0x816A001C\n.long 0xA86B0070\n.long 0x800B0074\n.long 0x7C6A1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0xC0230000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
