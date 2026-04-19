// 0x8008730C (8B) TextBaseItem::GetText(void) const
// Getter for field at offset 0x20.

class TextBaseItem {
public:
    char pad_000[0x20];
    int m_field_20;
    int GetText(void) const;
};

int TextBaseItem::GetText(void) const {
    return m_field_20;
}
