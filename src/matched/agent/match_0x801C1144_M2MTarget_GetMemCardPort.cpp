// 0x801C1144 (24B) M2MTarget::GetMemCardPort(void)

struct M2MTarget {
    char pad[268];
    int m_field_268;
    int m_field_272;
    int GetMemCardPort();
};

int M2MTarget::GetMemCardPort() {
    int v = m_field_268;
    if (v != -1) return v;
    return m_field_272;
}
