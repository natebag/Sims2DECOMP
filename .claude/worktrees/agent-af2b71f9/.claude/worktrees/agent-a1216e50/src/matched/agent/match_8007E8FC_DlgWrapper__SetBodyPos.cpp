// 0x8007E8FC (88 bytes)
// DlgWrapper::SetBodyPos(EVec2 &)

class DlgWrapper { public: void SetBodyPos(EVec2 &); };

__attribute__((naked))
void DlgWrapper::SetBodyPos(EVec2 &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x90010014\n.long 0x7C892378\n.long 0x39610008\n.long 0xC1A90000\n.long 0x7D645B78\n.long 0xC0090004\n.long 0xD1A10008\n.long 0xD00B0004\n.long 0x812300AC\n.long 0x81490064\n.long 0x816A001C\n.long 0xA86B0038\n.long 0x800B003C\n.long 0x7C6A1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x38210010\n.long 0x4E800020");
}
