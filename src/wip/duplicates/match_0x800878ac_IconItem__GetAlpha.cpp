struct IconItem {
    char pad[0x2C];
    float m_alpha;

    float GetAlpha(void);
};

float IconItem::GetAlpha(void) {
    return m_alpha;
}
