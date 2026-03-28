// 0x800A8B1C (8 bytes) — lwz 3, 20(3); blr
// AmbientScorePlayer::GetVolume(void)

class AmbientScorePlayer {
public:
    void GetVolume(void);
};

__attribute__((naked))
void AmbientScorePlayer::GetVolume(void) {
    asm volatile(
        "lwz 3, 20(3)\n"
        "blr\n"
    );
}
