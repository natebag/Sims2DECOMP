// 0x801c1144 M2MTarget::GetMemCardPort(void) (24B)

struct M2MTarget {
    char pad[0x010C];
    int m_port1;
    int m_port2;
    int GetMemCardPort(void);
};

int M2MTarget::GetMemCardPort(void) {
    if (m_port1 != -1) return m_port1;
    return m_port2;
}
