/* Interaction::SetID(int) - 0x800C1DAC (8 bytes) */

struct Interaction {
    char m_pad[0x38];
    int m_id;

    void SetID(int id);
};

void Interaction::SetID(int id) {
    m_id = id;
}
