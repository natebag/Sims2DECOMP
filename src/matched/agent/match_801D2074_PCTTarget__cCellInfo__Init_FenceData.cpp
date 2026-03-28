/* PCTTarget::cCellInfo::Init(int, FenceData *) at 0x801D2074 (68B) */

struct FenceData {
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

        int Init(int id, FenceData* fence);
    };
};

int PCTTarget::cCellInfo::Init(int id, FenceData* fence) {
    if (!fence) return 0;
    m_type = 2;
    m_id = id;
    m_data = fence;
    m_cost = fence->m_cost;
    if (m_cost == 0) {
        m_cost = (int)0xD59C7BB5u;
    }
    return 1;
}
