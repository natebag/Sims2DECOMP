// 0x801F74A4 (68 bytes)
// INVTarget::GetOnMsgInvShpCategoryCount(char *)

class INVTarget { public: void GetOnMsgInvShpCategoryCount(char *); };

__attribute__((naked))
void INVTarget::GetOnMsgInvShpCategoryCount(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C691B78\n.long 0x3D608040\n.long 0x80090178\n.long 0x7C832378\n.long 0x80A9017C\n.long 0x388B878C\n.long 0x7CA02850\n.long 0x7CA51E70\n.long 0x4CC63182\n.long 0x480E73B5\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
