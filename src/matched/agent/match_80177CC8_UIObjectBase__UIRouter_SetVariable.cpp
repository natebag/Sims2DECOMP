// 0x80177CC8 (68 bytes)
// UIObjectBase::UIRouter_SetVariable(char *, char *)

class UIObjectBase { public: void UIRouter_SetVariable(char *, char *); };

__attribute__((naked))
void UIObjectBase::UIRouter_SetVariable(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x3D208047\n.long 0x7C852378\n.long 0x81695EF8\n.long 0x7C641B78\n.long 0x812B0080\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
