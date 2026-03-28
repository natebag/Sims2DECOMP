// 0x801116A0 (72 bytes)
// ObjSelector::GetNormalSimDescription(void) const

class ObjSelector { public: void GetNormalSimDescription(void) const; };

__attribute__((naked))
void ObjSelector::GetNormalSimDescription(void) const {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630098\n.long 0x2C0B0000\n.long 0x4082000C\n.long 0x8063008C\n.long 0x4800001C\n.long 0x812B0004\n.long 0xA8690158\n.long 0x8009015C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
