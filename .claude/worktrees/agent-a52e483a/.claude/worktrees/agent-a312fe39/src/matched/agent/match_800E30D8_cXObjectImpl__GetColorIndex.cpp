// 0x800E30D8 (64 bytes)
// cXObjectImpl::GetColorIndex(void) const

class cXObjectImpl { public: void GetColorIndex(void) const; };

__attribute__((naked))
void cXObjectImpl::GetColorIndex(void) const {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80630004\n.long 0x38800037\n.long 0x81230004\n.long 0xA8090260\n.long 0x81290264\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x5463063E\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
