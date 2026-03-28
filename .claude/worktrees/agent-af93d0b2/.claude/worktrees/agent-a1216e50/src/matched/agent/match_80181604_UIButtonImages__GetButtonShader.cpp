// 0x80181604 (116 bytes)
// UIButtonImages::GetButtonShader(int)

class UIButtonImages { public: void GetButtonShader(int); };

__attribute__((naked))
void UIButtonImages::GetButtonShader(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x816D84FC\n.long 0x2C0B0000\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000040\n.long 0x547F103A\n.long 0x392B0038\n.long 0x7C09F82E\n.long 0x2C000000\n.long 0x40820020\n.long 0x7C8BF82E\n.long 0x3C60804C\n.long 0x3863BBDC\n.long 0x481A50D5\n.long 0x812D84FC\n.long 0x39290038\n.long 0x7C69F92E\n.long 0x812D84FC\n.long 0x39290038\n.long 0x7C69F82E\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
