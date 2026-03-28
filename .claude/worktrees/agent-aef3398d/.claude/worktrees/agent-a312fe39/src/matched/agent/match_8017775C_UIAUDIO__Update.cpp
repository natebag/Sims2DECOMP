// 0x8017775C (68 bytes)
// UIAUDIO::Update(void)

class UIAUDIO { public: void Update(void); };

__attribute__((naked))
void UIAUDIO::Update(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x3BE00000\n.long 0x7FE4FB78\n.long 0x7FC3F378\n.long 0x48000025\n.long 0x3BFF0001\n.long 0x2C1F0004\n.long 0x4081FFEC\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
