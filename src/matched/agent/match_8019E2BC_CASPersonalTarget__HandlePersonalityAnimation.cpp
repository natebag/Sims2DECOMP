// 0x8019E2BC (68 bytes)
// CASPersonalTarget::HandlePersonalityAnimation(char *)

class CASPersonalTarget { public: void HandlePersonalityAnimation(char *); };

__attribute__((naked))
void CASPersonalTarget::HandlePersonalityAnimation(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x81230084\n.long 0x83E90014\n.long 0x2C1F0000\n.long 0x41820014\n.long 0x48000025\n.long 0x7C641B78\n.long 0x7FE3FB78\n.long 0x4BFD241D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
