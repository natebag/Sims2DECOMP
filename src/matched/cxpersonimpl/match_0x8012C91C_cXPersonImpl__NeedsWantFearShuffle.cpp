// 0x8012C91C cXPersonImpl::NeedsWantFearShuffle (12B)

struct cXPerson_NeedsWantFearShuffle {
    char pad[0x9C];
    unsigned short m_flags;
    int NeedsWantFearShuffle();
};

int cXPerson_NeedsWantFearShuffle::NeedsWantFearShuffle() {
    return (m_flags >> 5) & 1;
}
