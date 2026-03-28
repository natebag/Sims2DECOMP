/* Interaction::SetTextColor(Interaction::tColor) - 0x800C1D2C (24 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetTextColor(int color);
};

void Interaction::SetTextColor(int color) {
    m_flags = (m_flags & ~(7 << 12)) | (color << 12);
}
