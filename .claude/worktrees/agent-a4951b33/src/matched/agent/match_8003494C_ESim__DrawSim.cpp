// 0x8003494C (92 bytes)
// ESim::DrawSim(bool)

class ESim { public: void DrawSim(bool); };

__attribute__((naked))
void ESim::DrawSim(bool) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x807F03D0\n.long 0x81230004\n.long 0xA8090238\n.long 0x8129023C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x38000000\n.long 0x40820008\n.long 0x7FC0F378\n.long 0x901F0428\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
