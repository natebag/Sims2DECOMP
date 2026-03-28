// 0x801F7EB0 (108 bytes)
// INVTarget::GetOnMsgInvShpIsPack(char *)

class INVTarget { public: void GetOnMsgInvShpIsPack(char *); };

__attribute__((naked))
void INVTarget::GetOnMsgInvShpIsPack(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x81230084\n.long 0x396D8FE4\n.long 0x386300D8\n.long 0x7C9F2378\n.long 0x5529103A\n.long 0x7C09582E\n.long 0x5400103A\n.long 0x7C63002E\n.long 0x4BFFFF6D\n.long 0x2C030000\n.long 0x38A00000\n.long 0x41820008\n.long 0x38A00001\n.long 0x3C808040\n.long 0x7FE3FB78\n.long 0x3884878C\n.long 0x4CC63182\n.long 0x480E6985\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
