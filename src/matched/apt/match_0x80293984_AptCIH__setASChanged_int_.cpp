// 0x80293984 (32B) AptCIH::setASChanged(int)

struct AptCIH_word5C_asc {
    unsigned int : 16;
    unsigned int asChanged : 1;
    unsigned int hasClass : 1;
    unsigned int zombieState : 2;
    unsigned int : 12;
};

struct AptCIH_ASC {
    char pad[0x5C];
    AptCIH_word5C_asc m_flags5C;

    void setASChanged(int v);
};

void AptCIH_ASC::setASChanged(int v) {
    m_flags5C.asChanged = (v != 0);
}
