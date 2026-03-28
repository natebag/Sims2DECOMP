// 0x801F66F8 (68 bytes)
// INVTarget::GetOnMsgInvObjectInfoReady(char *)

class INVTarget { public: void GetOnMsgInvObjectInfoReady(char *); };

__attribute__((naked))
void INVTarget::GetOnMsgInvObjectInfoReady(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030088\n.long 0x38A00000\n.long 0x7C832378\n.long 0x2C000000\n.long 0x41820008\n.long 0x38A00001\n.long 0x3C808040\n.long 0x3884878C\n.long 0x4CC63182\n.long 0x480E8161\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
