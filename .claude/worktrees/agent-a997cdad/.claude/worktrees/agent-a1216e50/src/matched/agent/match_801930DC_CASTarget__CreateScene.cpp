// 0x801930DC (112 bytes)
// CASTarget::CreateScene(int)

class CASTarget { public: void CreateScene(int); };

__attribute__((naked))
void CASTarget::CreateScene(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C842379\n.long 0x4180002C\n.long 0x2C040003\n.long 0x41810018\n.long 0x38600B20\n.long 0x4813E0B1\n.long 0x4BFE23D1\n.long 0x7C7F1B78\n.long 0x48000018\n.long 0x2C040005\n.long 0x38600000\n.long 0x40810020\n.long 0x38600000\n.long 0x48000018\n.long 0x2C1F0000\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4BFD22CD\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
