// 0x801DCDE8 (24B) R2LTarget::ScrollLeftEnabled(void)

struct R2LTarget {
    char pad[164];
    int m_count;
    bool ScrollLeftEnabled();
};

bool R2LTarget::ScrollLeftEnabled() {
    if (m_count > 0) return 1;
    return 0;
}
