/* Neighbor::ResetInterests(void) - 0x800CA978 (36 bytes) */

struct Interests {
    void SetInterests(void);
};

struct Neighbor {
    char m_pad[0x70];
    Interests m_interests;

    void ResetInterests(void);
};

void Neighbor::ResetInterests(void) {
    m_interests.SetInterests();
}
