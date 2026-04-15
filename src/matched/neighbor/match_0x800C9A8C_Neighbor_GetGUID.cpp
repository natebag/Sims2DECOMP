// 0x800C9A8C Neighbor::GetGUID (8B)
struct Neighbor {
    char pad[8];
    int m_guid;
    int GetGUID();
};

int Neighbor::GetGUID() { return m_guid; }
