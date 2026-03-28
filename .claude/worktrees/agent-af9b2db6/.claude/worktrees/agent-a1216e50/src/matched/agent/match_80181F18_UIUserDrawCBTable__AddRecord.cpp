// 0x80181F18 (104 bytes)
// UIUserDrawCBTable::AddRecord(char *, CBFunctor2<ERC *, structDrawCBparams *> *, char *)

class UIUserDrawCBTable { public: void AddRecord(char *, CBFunctor2<ERC *, structDrawCBparams *> *, char *); };

__attribute__((naked))
void UIUserDrawCBTable::AddRecord(char *, CBFunctor2<ERC *, structDrawCBparams *> *, char *) {
    asm volatile(".long 0x81430008\n.long 0x812A0004\n.long 0x91230008\n.long 0x2C090000\n.long 0x4182000C\n.long 0x38000000\n.long 0x90090000\n.long 0x908A0008\n.long 0x90AA000C\n.long 0x90CA0010\n.long 0x80030000\n.long 0x2C000000\n.long 0x40820018\n.long 0x91430000\n.long 0x900A0000\n.long 0x91430004\n.long 0x900A0004\n.long 0x4E800020\n.long 0x81230004\n.long 0x39600000\n.long 0x91490004\n.long 0x80030004\n.long 0x900A0000\n.long 0x91430004\n.long 0x916A0004\n.long 0x4E800020");
}
