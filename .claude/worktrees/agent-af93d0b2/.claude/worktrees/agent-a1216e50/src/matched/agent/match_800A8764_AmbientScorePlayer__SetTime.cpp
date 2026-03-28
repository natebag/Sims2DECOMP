// 0x800A8764 (8 bytes) — stfs 1, 52(3); blr
// AmbientScorePlayer::SetTime(float)

class AmbientScorePlayer {
public:
    void SetTime(float);
};

__attribute__((naked))
void AmbientScorePlayer::SetTime(float) {
    asm volatile(
        "stfs 1, 52(3)\n"
        "blr\n"
    );
}
