// 0x80199BAC (108 bytes)
// CASSelectionTarget::ScrollPageLeft(void)

class CASSelectionTarget { public: void ScrollPageLeft(void); };

__attribute__((naked))
void CASSelectionTarget::ScrollPageLeft(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F0548\n.long 0x2C000001\n.long 0x4182003C\n.long 0x3880000C\n.long 0x38A0000F\n.long 0x480008DD\n.long 0x7FE3FB78\n.long 0x48000195\n.long 0x813F0548\n.long 0x7FE3FB78\n.long 0x3929FFFF\n.long 0x913F0548\n.long 0x48000A05\n.long 0x7FE3FB78\n.long 0x38800000\n.long 0x38A00003\n.long 0x48000601\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
