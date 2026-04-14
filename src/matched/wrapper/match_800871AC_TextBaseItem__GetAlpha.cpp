// 0x800871AC (12 bytes)
struct EVec4 { float x; float y; float z; float w; };

class TextBaseItem {
public:
    char pad[68];
    EVec4 *m_color;

    float GetAlpha(void);
};

float TextBaseItem::GetAlpha(void) {
    return m_color->w;
}
