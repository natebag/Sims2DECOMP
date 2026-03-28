// 0x80194EC4 (68 bytes)
// CASTarget::GotoGame(void)

class CASTarget { public: void GotoGame(void); };

__attribute__((naked))
void CASTarget::GotoGame(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x4BFFD781\n.long 0x3C60803F\n.long 0x3863C358\n.long 0x4BFE2E29\n.long 0x7FC3F378\n.long 0x38800000\n.long 0x4BFFFFCD\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
