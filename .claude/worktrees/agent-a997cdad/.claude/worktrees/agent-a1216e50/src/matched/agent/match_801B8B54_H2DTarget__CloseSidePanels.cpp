// 0x801B8B54 (80 bytes)
// H2DTarget::CloseSidePanels(int)

class H2DTarget { public: void CloseSidePanels(int); };

__attribute__((naked))
void H2DTarget::CloseSidePanels(int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x549D103A\n.long 0x393E009C\n.long 0x7C69E82E\n.long 0x48012FF1\n.long 0x393E00A4\n.long 0x7C69E82E\n.long 0x48028AB5\n.long 0x3BDE00AC\n.long 0x7C7EE82E\n.long 0x4802A9F5\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
