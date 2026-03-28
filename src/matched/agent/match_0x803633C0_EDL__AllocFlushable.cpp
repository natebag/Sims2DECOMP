struct EDL {
    char _pad[0x18];
    char m_sub;
    void AllocFlushable(unsigned int a, int b);
};

void Impl_803633C0(void*, unsigned int, int);

void EDL::AllocFlushable(unsigned int a, int b) {
    Impl_803633C0(&m_sub, a, b);
}
