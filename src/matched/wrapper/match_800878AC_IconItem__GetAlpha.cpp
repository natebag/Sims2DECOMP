// 0x800878AC (8 bytes)
class IconItem {
public:
    char pad[44];
    float m_alpha;

    float GetAlpha(void);
};

float IconItem::GetAlpha(void) {
    return m_alpha;
}
