// 0x800A8B24 (8 bytes) — lwz 3, 8(3); blr
// AmbientScorePlayer::GetAmbientScore(void)

class AmbientScorePlayer {
public:
    void GetAmbientScore(void);
};

__attribute__((naked))
void AmbientScorePlayer::GetAmbientScore(void) {
    asm volatile(
        "lwz 3, 8(3)\n"
        "blr\n"
    );
}
