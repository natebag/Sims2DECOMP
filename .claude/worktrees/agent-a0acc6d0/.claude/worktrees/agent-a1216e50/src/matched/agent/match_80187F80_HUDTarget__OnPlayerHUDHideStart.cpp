// 0x80187F80 (124 bytes)
// HUDTarget::OnPlayerHUDHideStart(int)

class HUDTarget { public: void OnPlayerHUDHideStart(int); };

__attribute__((naked))
void HUDTarget::OnPlayerHUDHideStart(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9E2378\n.long 0x7C7F1B78\n.long 0x1C7E00B4\n.long 0x38630740\n.long 0x7C7F1A14\n.long 0x4BFFC405\n.long 0x7FE3FB78\n.long 0x7FC4F378\n.long 0x48000399\n.long 0x2C030000\n.long 0x40820024\n.long 0x1C7E031C\n.long 0x38630108\n.long 0x7C7F1A14\n.long 0x4BFFD3C1\n.long 0x7FE3FB78\n.long 0x7FC4F378\n.long 0x38A00000\n.long 0x480006E9\n.long 0x393F00E9\n.long 0x38000001\n.long 0x7C09F1AE\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
