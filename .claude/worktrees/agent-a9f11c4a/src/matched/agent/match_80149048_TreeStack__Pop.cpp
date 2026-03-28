// 0x80149048 (124 bytes)
// TreeStack::Pop(void)

class TreeStack { public: void Pop(void); };

__attribute__((naked))
void TreeStack::Pop(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x3BE30008\n.long 0x81230008\n.long 0x801F0004\n.long 0x7C090050\n.long 0x5409F0BF\n.long 0x40820038\n.long 0x81630018\n.long 0x39200001\n.long 0x912DA040\n.long 0x380003E9\n.long 0xB00B0034\n.long 0x388003E9\n.long 0x81630018\n.long 0x812B0040\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x813F0004\n.long 0x3929FFFC\n.long 0x913F0004\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
