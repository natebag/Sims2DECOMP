// 0x801F673C (64 bytes)
// INVTarget::GetOnMsgInvCurrentTab(char *)

class INVTarget { public: void GetOnMsgInvCurrentTab(char *); };

__attribute__((naked))
void INVTarget::GetOnMsgInvCurrentTab(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030084\n.long 0x392D8FDC\n.long 0x7C832378\n.long 0x5400103A\n.long 0x3C808040\n.long 0x7CA9002E\n.long 0x3884878C\n.long 0x4CC63182\n.long 0x480E8121\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
