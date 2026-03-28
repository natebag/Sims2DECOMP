// 0x800A9270 (76 bytes)
// AmbientSoundPlayer::AmbientSoundPlayer(void)

class AmbientSoundPlayer { public: void AmbientSoundPlayer(void); };

__attribute__((naked))
void AmbientSoundPlayer::AmbientSoundPlayer(void) {
    asm volatile(".long 0x3D60803E\n.long 0x7C691B78\n.long 0xC00B91F4\n.long 0x38000000\n.long 0x90090000\n.long 0x39690014\n.long 0x90090004\n.long 0x3940FFFF\n.long 0x90090008\n.long 0x9009000C\n.long 0x90090010\n.long 0xD0090014\n.long 0xD00B0008\n.long 0xD00B0004\n.long 0xD0090024\n.long 0x90090028\n.long 0x9149002C\n.long 0xD0090020\n.long 0x4E800020");
}
