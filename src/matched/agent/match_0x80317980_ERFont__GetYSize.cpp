struct ERFont {
    char _pad[0x4c];
    float m_ySize;
    float GetYSize();
};
float ERFont::GetYSize() { return m_ySize; }
