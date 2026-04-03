struct IconItem {
    char pad[0x2C];
    float m_alpha;

    void SetAlpha(float alpha);
};

void IconItem::SetAlpha(float alpha) {
    m_alpha = alpha;
}
