// 0x801B0CCC (80 bytes)
// FAMTarget::OnLotSelect(void)

class FAMTarget { public: void OnLotSelect(void); };

__attribute__((naked))
void FAMTarget::OnLotSelect(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x48000119\n.long 0x2C030000\n.long 0x41820014\n.long 0x7FE3FB78\n.long 0x38800001\n.long 0x48001915\n.long 0x48000010\n.long 0x7FE3FB78\n.long 0x38800002\n.long 0x48001905\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
