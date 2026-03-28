// 0x800A9338 (8 bytes) — stw 4, 4(3); blr
// AmbientSoundPlayer::SetAmbientSound(ERAmbientSound *)

class AmbientSoundPlayer {
public:
    void SetAmbientSound(ERAmbientSound *);
};

__attribute__((naked))
void AmbientSoundPlayer::SetAmbientSound(ERAmbientSound *) {
    asm volatile(
        "stw 4, 4(3)
"
        "blr
"
    );
}
