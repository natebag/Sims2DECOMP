// 0x800A8B2C (8 bytes) — lwz 3, 16(3); blr
// AmbientScorePlayer::GetNumPlaying(void)

class AmbientScorePlayer {
public:
    void GetNumPlaying(void);
};

__attribute__((naked))
void AmbientScorePlayer::GetNumPlaying(void) {
    asm volatile(
        "lwz 3, 16(3)\n"
        "blr\n"
    );
}
