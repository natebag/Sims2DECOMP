// 0x801F66B8 (64 bytes)
// INVTarget::GetOnMsgInvBackExitReset(char *)

class INVTarget { public: void GetOnMsgInvBackExitReset(char *); };

__attribute__((naked))
void INVTarget::GetOnMsgInvBackExitReset(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x3D208047\n.long 0x8009618C\n.long 0x2C000000\n.long 0x4182000C\n.long 0x4BFFA231\n.long 0x48000010\n.long 0x3D208040\n.long 0xA0098798\n.long 0xB0040000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
