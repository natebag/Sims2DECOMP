// 0x802B4894 (32B) AptValue::incGCRoot(void)

struct AptValueWord {
    unsigned int m_high : 18;
    unsigned int m_gcRoot : 6;
    unsigned int m_low : 8;
};

struct AptValue {
    AptValueWord m_word;
    void incGCRoot();
};

void AptValue::incGCRoot() {
    if (m_word.m_gcRoot > 62) return;
    m_word.m_gcRoot++;
}
