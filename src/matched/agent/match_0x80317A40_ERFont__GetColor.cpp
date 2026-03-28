struct ERFont {
    char _pad[0x58];
    int m_color;
    int *GetColor();
};
int *ERFont::GetColor() { return &m_color; }
