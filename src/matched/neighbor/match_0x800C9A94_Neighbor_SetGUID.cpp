// 0x800C9A94 Neighbor::SetGUID (8B)
struct Neighbor {
    char pad[8];
    int m_guid;
    void SetGUID(int g);
};

void Neighbor::SetGUID(int g) { m_guid = g; }
