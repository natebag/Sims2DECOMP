// 0x800EAFC0 (68 bytes)
// cXObjectImpl::EnableSim(bool)

class cXObjectImpl { public: void EnableSim(bool); };

__attribute__((naked))
void cXObjectImpl::EnableSim(bool) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630058\n.long 0x7C862378\n.long 0xA8830064\n.long 0x38A00001\n.long 0x812B0000\n.long 0xA8690240\n.long 0x80090244\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
