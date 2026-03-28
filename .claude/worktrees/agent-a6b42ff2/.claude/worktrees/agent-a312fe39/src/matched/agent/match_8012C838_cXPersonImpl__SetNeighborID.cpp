// 0x8012C838 (64 bytes)
// cXPersonImpl::SetNeighborID(short)

class cXPersonImpl { public: void SetNeighborID(short); };

__attribute__((naked))
void cXPersonImpl::SetNeighborID(short) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630004\n.long 0x7C852378\n.long 0x3880001F\n.long 0x812B0004\n.long 0xA8690140\n.long 0x80090144\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
