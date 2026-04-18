// 0x802939B0 (20B) AptCIH::setZombieState(int)

struct AptCIH_word5C {
    unsigned int : 16;
    unsigned int asChanged : 1;
    unsigned int hasClass : 1;
    unsigned int zombieState : 2;
    unsigned int : 12;
};

struct AptCIH {
    char pad[0x5C];
    AptCIH_word5C m_flags5C;

    void setZombieState(int v);
};

void AptCIH::setZombieState(int v) {
    m_flags5C.zombieState = v & 3;
}
