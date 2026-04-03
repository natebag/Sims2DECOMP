struct ERFont;

struct MUWrapper {
    char pad[0xA4];
    ERFont *m_font;

    ERFont *GetFont(void);
};

ERFont *MUWrapper::GetFont(void) {
    return m_font;
}
