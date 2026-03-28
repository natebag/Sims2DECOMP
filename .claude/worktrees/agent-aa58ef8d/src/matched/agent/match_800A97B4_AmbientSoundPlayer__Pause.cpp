// 0x800A97B4 (68 bytes)
// AmbientSoundPlayer::Pause(void)

class AmbientSoundPlayer { public: void Pause(void); };

__attribute__((naked))
void AmbientSoundPlayer::Pause(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630008\n.long 0x2C0B0000\n.long 0x4182001C\n.long 0x812B0000\n.long 0xA8690038\n.long 0x8009003C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
