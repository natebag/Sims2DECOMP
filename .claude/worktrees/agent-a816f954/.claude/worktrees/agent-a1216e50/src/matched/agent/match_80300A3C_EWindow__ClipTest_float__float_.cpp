// 0x80300A3C (72 bytes)
// EWindow::ClipTest(float, float)

class EWindow { public: void ClipTest(float, float); };

__attribute__((naked))
void EWindow::ClipTest(float, float) {
    asm volatile(".long 0xC0030060\n.long 0x38000000\n.long 0xFC010000\n.long 0x4C620B82\n.long 0x40830030\n.long 0xC0030068\n.long 0xFC010000\n.long 0x40800024\n.long 0xC0030064\n.long 0xFC020000\n.long 0x4C620B82\n.long 0x40830014\n.long 0xC003006C\n.long 0xFC020000\n.long 0x40800008\n.long 0x38000001\n.long 0x7C030378\n.long 0x4E800020");
}
