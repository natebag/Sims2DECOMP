/* Interaction::HasID(void) const - 0x800C1D8C (24 bytes) */

struct Interaction {
    char m_pad[0x38];
    int m_id;

    int HasID(void) const;
};

int Interaction::HasID(void) const {
    if (m_id != 0) {
        return 1;
    }
    return 0;
}
