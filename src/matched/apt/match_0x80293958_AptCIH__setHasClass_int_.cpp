// 0x80293958 (32B) AptCIH::setHasClass(int)

struct AptCIH_word5C_hc {
    unsigned int : 16;
    unsigned int asChanged : 1;
    unsigned int hasClass : 1;
    unsigned int zombieState : 2;
    unsigned int : 12;
};

struct AptCIH_HC {
    char pad[0x5C];
    AptCIH_word5C_hc m_flags5C;

    void setHasClass(int v);
};

void AptCIH_HC::setHasClass(int v) {
    m_flags5C.hasClass = (v != 0);
}
