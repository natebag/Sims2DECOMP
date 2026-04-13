/* Interaction::GetRunAsSub(void) const - 0x800C1FC4 (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetRunAsSub(void) const;
};

int Interaction::GetRunAsSub(void) const {
    return (m_flags >> 15) & 1;
}
