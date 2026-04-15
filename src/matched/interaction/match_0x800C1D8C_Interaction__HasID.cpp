/* Interaction::HasID(void) const - 0x800C1D8C (24 bytes) */
struct Interaction {
    char pad0[56];
    int m_id;
    int HasID(void) const;
};
int Interaction::HasID(void) const {
    return m_id != 0 ? 1 : 0;
}
