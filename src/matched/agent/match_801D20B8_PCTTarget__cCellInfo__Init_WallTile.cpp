/* PCTTarget::cCellInfo::Init(int, WallTile *) at 0x801D20B8 (68B) */

struct WallTile {
    int m_pad00;
    int m_pad04;
    int m_cost;
};

struct PCTTarget {
    struct cCellInfo {
        int m_type;
        int m_id;
        int m_cost;
        int m_pad0C;
        int m_pad10;
        void* m_data;

        int Init(int id, WallTile* wall);
    };
};

int PCTTarget::cCellInfo::Init(int id, WallTile* wall) {
    if (!wall) return 0;
    m_type = 3;
    m_id = id;
    m_data = wall;
    m_cost = wall->m_cost;
    if (m_cost == 0) {
        m_cost = (int)0xD59C7BB5u;
    }
    return 1;
}
