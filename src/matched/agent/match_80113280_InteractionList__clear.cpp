// 0x80113280 (112 bytes)
// InteractionList::clear(void)

class InteractionList { public: void clear(void); };

__attribute__((naked))
void InteractionList::clear(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x83FE0000\n.long 0x2C1F0000\n.long 0x41820034\n.long 0x7FEBFB78\n.long 0x83FF0000\n.long 0x2C0B0000\n.long 0x4182FFEC\n.long 0x812B0040\n.long 0x38800003\n.long 0xA8690008\n.long 0x8009000C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x4BFFFFCC\n.long 0x38000000\n.long 0x901E0000\n.long 0x901E0004\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
