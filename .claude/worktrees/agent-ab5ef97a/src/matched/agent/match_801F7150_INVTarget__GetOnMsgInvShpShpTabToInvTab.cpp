// 0x801F7150 (104 bytes)
// INVTarget::GetOnMsgInvShpShpTabToInvTab(char *)

class INVTarget { public: void GetOnMsgInvShpShpTabToInvTab(char *); };

__attribute__((naked))
void INVTarget::GetOnMsgInvShpShpTabToInvTab(char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x7C9C2378\n.long 0x4800CC01\n.long 0x813E0178\n.long 0x54631838\n.long 0x7C69182E\n.long 0x4BFF5C4D\n.long 0x7C7D1B78\n.long 0x7FA4EB78\n.long 0x7FC3F378\n.long 0x4BFF8F6D\n.long 0x3C808040\n.long 0x7F83E378\n.long 0x3884878C\n.long 0x38BDFFFF\n.long 0x4CC63182\n.long 0x480E76E9\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
