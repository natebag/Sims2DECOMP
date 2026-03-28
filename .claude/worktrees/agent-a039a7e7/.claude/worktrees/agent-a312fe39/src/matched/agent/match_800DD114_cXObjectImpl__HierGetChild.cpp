// 0x800DD114 (72 bytes)
// cXObjectImpl::HierGetChild(int)

class cXObjectImpl { public: void HierGetChild(int); };

__attribute__((naked))
void cXObjectImpl::HierGetChild(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81430004\n.long 0x54842834\n.long 0x81230090\n.long 0x816A0004\n.long 0x7D292214\n.long 0xA86B0488\n.long 0x800B048C\n.long 0x7C6A1A14\n.long 0xA8890004\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
