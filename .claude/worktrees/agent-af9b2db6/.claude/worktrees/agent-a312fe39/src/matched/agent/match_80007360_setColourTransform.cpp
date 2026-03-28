// 0x80007360 (88 bytes)
// setColourTransform(AptCXForm *)

struct AptCXForm;
__attribute__((naked))
void setColourTransform(AptCXForm *) {
    asm volatile(".long 0x80A30000\n.long 0x3D008047\n.long 0x80E30008\n.long 0x3928F8E0\n.long 0x8003000C\n.long 0x39630010\n.long 0x80830004\n.long 0x3CC08047\n.long 0x90A8F8E0\n.long 0x3946F8F0\n.long 0x9009000C\n.long 0x90890004\n.long 0x90E90008\n.long 0x80030010\n.long 0x812B000C\n.long 0x810B0004\n.long 0x80EB0008\n.long 0x9006F8F0\n.long 0x912A000C\n.long 0x910A0004\n.long 0x90EA0008\n.long 0x4E800020");
}
