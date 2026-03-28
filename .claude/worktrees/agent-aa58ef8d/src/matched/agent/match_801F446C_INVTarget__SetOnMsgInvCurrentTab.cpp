// 0x801F446C (88 bytes)
// INVTarget::SetOnMsgInvCurrentTab(char *)

class INVTarget { public: void SetOnMsgInvCurrentTab(char *); };

__attribute__((naked))
void INVTarget::SetOnMsgInvCurrentTab(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C832378\n.long 0x480EA7CD\n.long 0x3D208047\n.long 0x7C641B78\n.long 0x8009618C\n.long 0x2C000000\n.long 0x41820010\n.long 0x7FE3FB78\n.long 0x4BFFB061\n.long 0x4800000C\n.long 0x7FE3FB78\n.long 0x4BFFBBA5\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
