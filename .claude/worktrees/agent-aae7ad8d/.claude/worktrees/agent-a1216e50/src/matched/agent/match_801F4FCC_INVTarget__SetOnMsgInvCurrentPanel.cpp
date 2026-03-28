// 0x801F4FCC (64 bytes)
// INVTarget::SetOnMsgInvCurrentPanel(char *)

class INVTarget { public: void SetOnMsgInvCurrentPanel(char *); };

__attribute__((naked))
void INVTarget::SetOnMsgInvCurrentPanel(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x7C832378\n.long 0x480E9C6D\n.long 0x68630001\n.long 0x20030000\n.long 0x7C601914\n.long 0x907E3198\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
