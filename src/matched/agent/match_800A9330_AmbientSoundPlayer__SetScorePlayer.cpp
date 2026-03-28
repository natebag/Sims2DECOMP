// 0x800A9330 (8 bytes) — stw 4, 0(3); blr
// AmbientSoundPlayer::SetScorePlayer(AmbientScorePlayer *)

class AmbientSoundPlayer {
public:
    void SetScorePlayer(AmbientScorePlayer *);
};

__attribute__((naked))
void AmbientSoundPlayer::SetScorePlayer(AmbientScorePlayer *) {
    asm volatile(
        "stw 4, 0(3)
"
        "blr
"
    );
}
