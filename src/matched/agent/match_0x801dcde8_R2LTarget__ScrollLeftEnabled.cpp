// 0x801dcde8 R2LTarget::ScrollLeftEnabled(void) (24B)

struct R2LTarget {
    char pad[0xA4];
    int m_scrollLeft;
    int ScrollLeftEnabled(void);
};

int R2LTarget::ScrollLeftEnabled(void) {
    return m_scrollLeft > 0;
}
