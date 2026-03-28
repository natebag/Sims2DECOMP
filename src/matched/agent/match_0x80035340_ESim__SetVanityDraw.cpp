/* ESim::SetVanityDraw(bool, unsigned int) - 0x80035340 (12 bytes) */

struct ESim {
    char pad[0x3D4];
    unsigned int m_vanityColor;
    char pad2[0x04];
    int m_vanityDraw;

    void SetVanityDraw(bool draw, unsigned int color);
};

void ESim::SetVanityDraw(bool draw, unsigned int color) {
    m_vanityColor = color;
    m_vanityDraw = draw;
}
