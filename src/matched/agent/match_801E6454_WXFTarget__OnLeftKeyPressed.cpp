// 0x801E6454 (104 bytes)
// WXFTarget::OnLeftKeyPressed(char *, char *)

class WXFTarget { public: void OnLeftKeyPressed(char *, char *); };

__attribute__((naked))
void WXFTarget::OnLeftKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FEF0\n.long 0x7C0802A6\n.long 0xBFC10108\n.long 0x90010114\n.long 0x7C7E1B78\n.long 0x3C80803F\n.long 0x80BE008C\n.long 0x3884DDA0\n.long 0x38610008\n.long 0x20050000\n.long 0x7CA02914\n.long 0x4CC63182\n.long 0x480F8405\n.long 0x813E0080\n.long 0x38A10008\n.long 0x808D8FCC\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C7E1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010114\n.long 0x7C0803A6\n.long 0xBBC10108\n.long 0x38210110\n.long 0x4E800020");
}
