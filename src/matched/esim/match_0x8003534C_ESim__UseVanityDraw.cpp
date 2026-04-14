/* ESim::UseVanityDraw(unsigned int *) - 0x8003534C (16 bytes) */

struct ESim {
    char pad[0x3D4];
    unsigned int m_vanityColor;
    char pad2[0x04];
    int m_vanityDraw;

    int UseVanityDraw(unsigned int *outColor);
};

int ESim::UseVanityDraw(unsigned int *outColor) {
    *outColor = m_vanityColor;
    return m_vanityDraw;
}
