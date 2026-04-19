// 0x802B638C (32B) AptObject::setHasClass(int)
// Set bit 8 of flags-word at offset 0x20 via rlwimi.
// Normalization uses "li 1 / bne skip / li 0" form (inverse of setIsDefined).

struct AptObjectFlags {
    unsigned int _b0_b7      : 8;
    unsigned int hasClass    : 1;  // bit 8
    unsigned int _rest       : 23;
};

class AptObject {
public:
    char pad_000[0x20];
    AptObjectFlags m_flags;
    void setHasClass(int v);
};

void AptObject::setHasClass(int v) {
    m_flags.hasClass = (v != 0);
}
