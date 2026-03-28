// 0x800A876C (8 bytes) — lfs 1, 52(3); blr
// AmbientScorePlayer::GetTime(void)

class AmbientScorePlayer {
public:
    void GetTime(void);
};

__attribute__((naked))
void AmbientScorePlayer::GetTime(void) {
    asm volatile(
        "lfs 1, 52(3)\n"
        "blr\n"
    );
}
