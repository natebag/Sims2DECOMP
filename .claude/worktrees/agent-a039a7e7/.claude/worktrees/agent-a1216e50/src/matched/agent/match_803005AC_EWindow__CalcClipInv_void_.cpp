// 0x803005AC (84 bytes)
// EWindow::CalcClipInv(void)

class EWindow { public: void CalcClipInv(void); };

__attribute__((naked))
void EWindow::CalcClipInv(void) {
    asm volatile(".long 0xC1030030\n.long 0xC0E30034\n.long 0xC1830070\n.long 0xC1630074\n.long 0xC0030078\n.long 0xED8C4028\n.long 0xC1A3007C\n.long 0xED6B3828\n.long 0xC1430000\n.long 0xEC004028\n.long 0xC1230014\n.long 0xEDAD3828\n.long 0xEC005024\n.long 0xEDAD4824\n.long 0xD0030068\n.long 0xED8C5024\n.long 0xD1A3006C\n.long 0xED6B4824\n.long 0xD1830060\n.long 0xD1630064\n.long 0x4E800020");
}
