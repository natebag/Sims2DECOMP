// 0x800878A4 (8 bytes)
class IconItem {
public:
    char pad[44];
    float m_alpha;

    void SetAlpha(float alpha);
};

void IconItem::SetAlpha(float alpha) {
    m_alpha = alpha;
}
