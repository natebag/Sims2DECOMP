// 0x800E3118 (116 bytes)
// cXObjectImpl::SetColorIndex(unsigned char)

class cXObjectImpl { public: void SetColorIndex(unsigned char); };

__attribute__((naked))
void cXObjectImpl::SetColorIndex(unsigned char) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x7C9C2378\n.long 0x817E0004\n.long 0x812B0004\n.long 0x800904BC\n.long 0xA86904B8\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x817E0004\n.long 0x7C7D1B78\n.long 0x7F85E378\n.long 0x38800037\n.long 0x812B0004\n.long 0xA86901E8\n.long 0x800901EC\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7FA3EB78\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
