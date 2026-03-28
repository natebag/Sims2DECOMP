// 0x8010A9D8 (76 bytes)
// fround(float)

__attribute__((naked))
void fround(float) {
    asm volatile(".long 0x9421FFF0\n.long 0x3D20803E\n.long 0xC009C220\n.long 0xFC010000\n.long 0x41800018\n.long 0x3D20803E\n.long 0xFC000890\n.long 0xC9A9C228\n.long 0xFC00682A\n.long 0x48000014\n.long 0x3D20803E\n.long 0xFC000890\n.long 0xC9A9C228\n.long 0xFC006828\n.long 0xFD80001E\n.long 0xD9810008\n.long 0x8061000C\n.long 0x38210010\n.long 0x4E800020");
}
