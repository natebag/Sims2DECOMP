// 0x801F7FE0 (68 bytes)
// INVTarget::GetOnMsgInvBldDisplayInfo(char *)

class INVTarget { public: void GetOnMsgInvBldDisplayInfo(char *); };

__attribute__((naked))
void INVTarget::GetOnMsgInvBldDisplayInfo(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800332E4\n.long 0x38A00000\n.long 0x7C832378\n.long 0x2C000000\n.long 0x41820008\n.long 0x38A00001\n.long 0x3C808040\n.long 0x3884878C\n.long 0x4CC63182\n.long 0x480E6879\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
