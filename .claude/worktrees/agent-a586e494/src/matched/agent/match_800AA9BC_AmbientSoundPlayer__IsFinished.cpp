// 0x800AA9BC (92 bytes)
// AmbientSoundPlayer::IsFinished(void)

class AmbientSoundPlayer { public: void IsFinished(void); };

__attribute__((naked))
void AmbientSoundPlayer::IsFinished(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x81630008\n.long 0x3BE00000\n.long 0x2C0B0000\n.long 0x41820024\n.long 0x812B0000\n.long 0xA8690028\n.long 0x8009002C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x40820008\n.long 0x3BE00001\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
