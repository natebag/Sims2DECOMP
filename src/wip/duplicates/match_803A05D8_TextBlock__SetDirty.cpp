/* 0x803A05D8 (16 bytes) - TextBlock::SetDirty(void) */
class TextBlock {
    char pad[56];
    unsigned int m_flags;
public:
    void SetDirty();
};
void TextBlock::SetDirty() { m_flags |= 0x10000000; }
