// 0x802B63B8 (32B) AptObject::setInMainInst(int)
// Set bit 9 of flags-word at offset 0x20 via rlwimi.

struct AptObjectFlags {
    unsigned int _b0_b8      : 9;
    unsigned int inMainInst  : 1;  // bit 9
    unsigned int _rest       : 22;
};

class AptObject {
public:
    char pad_000[0x20];
    AptObjectFlags m_flags;
    void setInMainInst(int v);
};

void AptObject::setInMainInst(int v) {
    m_flags.inMainInst = (v != 0);
}
