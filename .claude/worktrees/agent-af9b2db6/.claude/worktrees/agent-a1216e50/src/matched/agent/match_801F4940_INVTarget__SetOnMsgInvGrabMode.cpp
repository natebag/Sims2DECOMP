// 0x801F4940 (96 bytes)
// INVTarget::SetOnMsgInvGrabMode(char *)

class INVTarget { public: void SetOnMsgInvGrabMode(char *); };

__attribute__((naked))
void INVTarget::SetOnMsgInvGrabMode(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030084\n.long 0x392D8FDC\n.long 0x5400103A\n.long 0x7C09002E\n.long 0x2C000001\n.long 0x41820024\n.long 0x41810010\n.long 0x2C000000\n.long 0x41820010\n.long 0x48000020\n.long 0x2C000002\n.long 0x40820018\n.long 0x4BFFD645\n.long 0x48000010\n.long 0x38800000\n.long 0x38A00001\n.long 0x48002D1D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
