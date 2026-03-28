struct AptCIH {
    char pad[0x48];
    AptCIH* m_parent;
};

struct AptAnimationPoolData {
    char pad[0x94];
    AptCIH* m_inputMask;

    int isInputMasked(AptCIH* cih);
};

int AptAnimationPoolData::isInputMasked(AptCIH* cih) {
    AptCIH* mask = m_inputMask;
    if (mask == 0) return 0;
    AptCIH* p = cih;
    while (p != 0) {
        if (p == mask) return 0;
        p = p->m_parent;
    }
    return 1;
}
