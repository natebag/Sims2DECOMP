// 0x800871A0 (12 bytes)
struct EVec4 { float x; float y; float z; float w; };

class TextBaseItem {
public:
    char pad[68];
    EVec4 *m_color;

    void SetAlpha(float alpha);
};

void TextBaseItem::SetAlpha(float alpha) {
    m_color->w = alpha;
}
