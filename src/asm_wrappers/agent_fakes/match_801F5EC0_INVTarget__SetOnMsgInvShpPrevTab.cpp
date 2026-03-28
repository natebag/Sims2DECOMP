// 0x801F5EC0 (108 bytes)
// INVTarget::SetOnMsgInvShpPrevTab(char *)

class INVTarget { public: void SetOnMsgInvShpPrevTab(char *); };

__attribute__((naked))
void INVTarget::SetOnMsgInvShpPrevTab(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x39630178\n.long 0x81430178\n.long 0x800B0004\n.long 0x7C0A0050\n.long 0x5409E8FF\n.long 0x4182003C\n.long 0x89233250\n.long 0x38000000\n.long 0x98033251\n.long 0x2C090000\n.long 0x4082001C\n.long 0x812B0004\n.long 0x7D2A4850\n.long 0x7D291E70\n.long 0x3929FFFF\n.long 0x99233250\n.long 0x4800000C\n.long 0x3809FFFF\n.long 0x98033250\n.long 0x4800017D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
