// ActionQueueHUD::UpdateVisual(void) @ 0x80185820 (80B)

struct AQH_UV {
    char _pad1[0x150];
    int m_count;
    char _pad2[0x14];
    unsigned char m_f168;
    char _pad3[0x19F];
    unsigned char m_f308;
    unsigned char m_f309;
    unsigned char m_f30A;
    void UpdateVisual();
};

void AQH_UV::UpdateVisual() {
    int count = m_count;
    unsigned char f168 = m_f168;
    int pre5 = f168 == 5;
    for (int i = 0; i < count; i++) {
        if (f168 == 6) continue;
        if (!m_f308) continue;
        if ((unsigned)i < m_f309) continue;
        int vis = f168 >= 1;
        (void)(pre5 + vis);
    }
}
