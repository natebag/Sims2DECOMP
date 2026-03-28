struct TextBlock {
    char _p[0x38];
    unsigned int m_flags;
    void SetDirty();
};
void TextBlock::SetDirty() { m_flags |= 0x10000000; }
