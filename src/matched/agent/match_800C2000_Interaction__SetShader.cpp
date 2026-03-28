// 0x800C2000 (8 bytes) — li 3, 0; blr
// Interaction::SetShader(EActionIcon *) const

class Interaction {
public:
    void SetShader(EActionIcon *) const;
};

__attribute__((naked))
void Interaction::SetShader(EActionIcon *) const {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
