// 0x802907E4 (64B) AptCIH::Release(char *, char *, int)

struct AptValue {
    void Release(char* a, char* b, int c);
};

struct AptCIH : public AptValue {
    char pad[0x58];
    unsigned int m_flags5C;
    void Release(char* a, char* b, int c);
};

void AptCIH::Release(char* a, char* b, int c) {
    unsigned int flags = m_flags5C;
    unsigned int vtable = *(unsigned int*)this;
    unsigned int field = (flags >> 12) & 3;
    unsigned int vt = (vtable >> 14) & 0xFFF;
    if (field == 1 && vt == 1) {
        return;
    }
    AptValue::Release(a, b, c);
}
