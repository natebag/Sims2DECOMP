// 0x801F44C4 (88 bytes)
// INVTarget::SetOnMsgInvCurrentCell(char *)

class INVTarget { public: void SetOnMsgInvCurrentCell(char *); };

__attribute__((naked))
void INVTarget::SetOnMsgInvCurrentCell(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C832378\n.long 0x480EA775\n.long 0x801F0084\n.long 0x3D208047\n.long 0x8149618C\n.long 0x396D8FE4\n.long 0x5400103A\n.long 0x7C6B012E\n.long 0x2C0A0000\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4BFFC485\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
