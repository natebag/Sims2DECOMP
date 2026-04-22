// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// 0x802B48B4 (32B) AptValue::decGCRoot(void)

struct AptValue {
    union {
        int raw;
        struct {
            unsigned int pad2 : 18;
            unsigned int gcRoot : 6;
            unsigned int pad1 : 8;
        };
    } m_flags;

    void decGCRoot();
};

void AptValue::decGCRoot() {
    if (m_flags.gcRoot == 0) {
        return;
    }
    m_flags.gcRoot--;
}
