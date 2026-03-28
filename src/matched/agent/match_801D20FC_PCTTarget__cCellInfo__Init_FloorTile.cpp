/* PCTTarget::cCellInfo::Init(int, FloorTile *) at 0x801D20FC (68B) */

struct FloorTile {
    int m_pad00;
    int m_pad04;
    int m_pad08;
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

        int Init(int id, FloorTile* floor);
    };
};

int PCTTarget::cCellInfo::Init(int id, FloorTile* floor) {
    if (!floor) return 0;
    m_type = 4;
    m_id = id;
    m_data = floor;
    m_cost = floor->m_cost;
    if (m_cost == 0) {
        m_cost = (int)0xD59C7BB5u;
    }
    return 1;
}
