// 0x801B3024 (80 bytes)
// FAMTarget::GetLotName(int)

class FAMTarget { public: void GetLotName(int); };

__attribute__((naked))
void FAMTarget::GetLotName(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x90010014\n.long 0x7C832378\n.long 0x4BE70695\n.long 0x7C651B78\n.long 0x3C808047\n.long 0x38610008\n.long 0x38845DCC\n.long 0x4CC63182\n.long 0x4BE8CAC1\n.long 0x81210008\n.long 0x38600000\n.long 0x2C090000\n.long 0x41820008\n.long 0x80690000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x38210010\n.long 0x4E800020");
}
