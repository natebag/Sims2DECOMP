// 0x80083964 (8 bytes)
typedef void ERFont;

class MUWrapper {
public:
    char pad[164];
    ERFont *m_font;

    ERFont *GetFont(void);
};

ERFont *MUWrapper::GetFont(void) {
    return m_font;
}
