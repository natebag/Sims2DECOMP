// 0x800EB040 (64 bytes)
// cXObjectImpl::SetIdleStatus(int)

class cXObjectImpl { public: void SetIdleStatus(int); };

__attribute__((naked))
void cXObjectImpl::SetIdleStatus(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630058\n.long 0x7C852378\n.long 0xA8830064\n.long 0x812B0000\n.long 0xA8690228\n.long 0x8009022C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
