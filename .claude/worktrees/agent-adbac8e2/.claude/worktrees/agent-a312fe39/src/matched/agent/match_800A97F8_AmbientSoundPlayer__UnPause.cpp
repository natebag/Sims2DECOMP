// 0x800A97F8 (68 bytes)
// AmbientSoundPlayer::UnPause(void)

class AmbientSoundPlayer { public: void UnPause(void); };

__attribute__((naked))
void AmbientSoundPlayer::UnPause(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630008\n.long 0x2C0B0000\n.long 0x4182001C\n.long 0x812B0000\n.long 0xA8690040\n.long 0x80090044\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
