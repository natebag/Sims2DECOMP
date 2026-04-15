/* Interaction::SetID(int) - 0x800C1DAC (8 bytes) */
struct Interaction {
    char pad0[56];
    int m_id;
    void SetID(int id);
};
void Interaction::SetID(int id) { m_id = id; }
