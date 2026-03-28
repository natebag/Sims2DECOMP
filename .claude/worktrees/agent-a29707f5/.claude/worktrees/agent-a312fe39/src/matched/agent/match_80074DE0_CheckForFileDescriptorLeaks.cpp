// 0x80074DE0 (64 bytes)
// CheckForFileDescriptorLeaks(char *, int)

__attribute__((naked))
void CheckForFileDescriptorLeaks(char *, int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816D98F0\n.long 0x7C852378\n.long 0x7C641B78\n.long 0x812B0000\n.long 0xA8690030\n.long 0x80090034\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
