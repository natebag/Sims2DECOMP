// 0x8005656C (40B) ISimInstance::SetHighlight(unsigned int, bool)
// Sets or clears bits in m_flags at offset +0x32C based on bool parameter.

struct ISimInstance {
    char _pad[0x32C];
    unsigned int m_flags;
    void SetHighlight(unsigned int mask, bool highlight);
};

void ISimInstance::SetHighlight(unsigned int mask, bool highlight) {
    if (highlight) {
        m_flags |= mask;
    } else {
        m_flags &= ~mask;
    }
}
