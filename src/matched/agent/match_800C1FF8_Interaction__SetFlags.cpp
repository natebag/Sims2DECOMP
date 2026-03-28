/* Interaction::SetFlags(int) - 0x800C1FF8 (8 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetFlags(int f);
};

void Interaction::SetFlags(int f) {
    m_flags = f;
}
