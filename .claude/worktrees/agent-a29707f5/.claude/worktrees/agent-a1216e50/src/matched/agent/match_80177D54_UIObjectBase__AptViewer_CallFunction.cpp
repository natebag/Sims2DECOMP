// 0x80177D54 (84 bytes)
// UIObjectBase::AptViewer_CallFunction(char *, char *, char *, int, char **)

class UIObjectBase { public: void AptViewer_CallFunction(char *, char *, char *, int, char **); };

__attribute__((naked))
void UIObjectBase::AptViewer_CallFunction(char *, char *, char *, int, char **) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x3D208047\n.long 0x7C802378\n.long 0x7CAB2B78\n.long 0x7CCA3378\n.long 0x7CE83B78\n.long 0x80695E80\n.long 0x7FC4F378\n.long 0x7C050378\n.long 0x7D665B78\n.long 0x7D475378\n.long 0x4BE98721\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
