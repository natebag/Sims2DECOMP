// 0x800AA9B4 (8 bytes) — lwz 3, 4(3); blr
// AmbientSoundPlayer::GetAmbientSound(void)

class AmbientSoundPlayer {
public:
    void GetAmbientSound(void);
};

__attribute__((naked))
void AmbientSoundPlayer::GetAmbientSound(void) {
    asm volatile(
        "lwz 3, 4(3)\n"
        "blr\n"
    );
}
