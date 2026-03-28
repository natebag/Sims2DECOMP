// 0x80300A84 (100 bytes)
// EWindow::ClipTest(TRect<float> &)

class EWindow { public: void ClipTest(TRect<float> &); };

__attribute__((naked))
void EWindow::ClipTest(TRect<float> &) {
    asm volatile(".long 0xC1A30060\n.long 0x39230060\n.long 0xC0040000\n.long 0x38600000\n.long 0xFC006800\n.long 0x4C620B82\n.long 0x40830044\n.long 0xC1A40008\n.long 0xC0090008\n.long 0xFC0D0000\n.long 0x4C620382\n.long 0x40830030\n.long 0xC1A40004\n.long 0xC0090004\n.long 0xFC0D0000\n.long 0x4C620B82\n.long 0x4083001C\n.long 0xC1A4000C\n.long 0xC009000C\n.long 0xFC0D0000\n.long 0x4C620382\n.long 0x40830008\n.long 0x38600001\n.long 0x68630001\n.long 0x4E800020");
}
