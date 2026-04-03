struct ERFont {
    char _pad[0x50];
    float m_aspect;
    float GetAspect();
};
float ERFont::GetAspect() { return m_aspect; }
