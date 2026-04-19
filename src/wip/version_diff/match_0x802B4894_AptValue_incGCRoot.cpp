// 0x802B4894 (32 bytes)

struct AptValueWord {
    unsigned int m_high : 18;   // bits 14-31
    unsigned int m_gcRoot : 6;  // bits 8-13
    unsigned int m_low : 8;     // bits 0-7
};

struct AptValue {
    AptValueWord m_word;
    void incGCRoot();
};

void AptValue::incGCRoot() {
    register unsigned int v asm("r0") = *(unsigned int*)this;
    unsigned int count = (v >> 8) & 0x3F;
    if (count > 62) return;
    count++;
    *(unsigned int*)this = (v & ~0x3F00u) | (count << 8);
}
