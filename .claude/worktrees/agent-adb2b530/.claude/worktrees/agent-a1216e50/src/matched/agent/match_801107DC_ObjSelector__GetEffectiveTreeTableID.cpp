// 0x801107DC (76 bytes)
// ObjSelector::GetEffectiveTreeTableID(void)

class ObjSelector { public: void GetEffectiveTreeTableID(void); };

__attribute__((naked))
void ObjSelector::GetEffectiveTreeTableID(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B78\n.long 0x812B0038\n.long 0xA869000E\n.long 0x2C030000\n.long 0x40800020\n.long 0x2C03FFFF\n.long 0x38600000\n.long 0x40820014\n.long 0x7D635B78\n.long 0x48000035\n.long 0x81230038\n.long 0xA869000E\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
