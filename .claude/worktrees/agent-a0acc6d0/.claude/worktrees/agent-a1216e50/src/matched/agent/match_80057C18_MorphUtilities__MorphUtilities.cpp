// 0x80057C18 (8 bytes) — stw 4, 0(3); blr
// MorphUtilities::MorphUtilities(EIStaticModel **)

class MorphUtilities {
public:
    void MorphUtilities(EIStaticModel **);
};

__attribute__((naked))
void MorphUtilities::MorphUtilities(EIStaticModel **) {
    asm volatile(
        "stw 4, 0(3)\n"
        "blr\n"
    );
}
