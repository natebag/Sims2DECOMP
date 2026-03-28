/* Interaction::GetID(void) const - 0x800C1DA4 (8 bytes) */

struct Interaction {
    char m_pad[0x38];
    int m_id;

    int GetID(void) const;
};

int Interaction::GetID(void) const {
    return m_id;
}
