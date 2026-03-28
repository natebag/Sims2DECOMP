// 0x800A8B34 (8 bytes) — addi 3, 3, 32; blr
// AmbientScorePlayer::GetListenerInfos(void)

class AmbientScorePlayer {
public:
    void GetListenerInfos(void);
};

__attribute__((naked))
void AmbientScorePlayer::GetListenerInfos(void) {
    asm volatile(
        "addi 3, 3, 32
"
        "blr
"
    );
}
