// 0x802935B4 (60B) AptCIH::decZombieCount(void)
// m_zombieCount at offset 0x5C (unsigned short); calls AptUpdateZombieVector(false) on zero.

extern void AptUpdateZombieVector(bool);

struct AptCIH {
    char pad[0x5C];
    unsigned short m_zombieCount;
    void decZombieCount();
};

void AptCIH::decZombieCount() {
    if (--m_zombieCount == 0) {
        AptUpdateZombieVector(false);
    }
}
