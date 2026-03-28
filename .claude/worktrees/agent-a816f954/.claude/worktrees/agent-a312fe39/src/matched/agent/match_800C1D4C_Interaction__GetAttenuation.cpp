// 0x800C1D4C (8 bytes) — lfs 1, 48(3); blr
// Interaction::GetAttenuation(void) const

class Interaction {
public:
    void GetAttenuation(void) const;
};

__attribute__((naked))
void Interaction::GetAttenuation(void) const {
    asm volatile(
        "lfs 1, 48(3)\n"
        "blr\n"
    );
}
