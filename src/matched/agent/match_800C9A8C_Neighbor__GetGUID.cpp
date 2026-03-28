/* Neighbor::GetGUID(void) - 0x800C9A8C (8 bytes) */

struct Neighbor {
    char m_pad[0x08];
    int m_guid;

    int GetGUID(void);
};

int Neighbor::GetGUID(void) {
    return m_guid;
}
