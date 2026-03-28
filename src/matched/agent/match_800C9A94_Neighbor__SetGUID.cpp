/* Neighbor::SetGUID(int) - 0x800C9A94 (8 bytes) */

struct Neighbor {
    char m_pad[0x08];
    int m_guid;

    void SetGUID(int guid);
};

void Neighbor::SetGUID(int guid) {
    m_guid = guid;
}
