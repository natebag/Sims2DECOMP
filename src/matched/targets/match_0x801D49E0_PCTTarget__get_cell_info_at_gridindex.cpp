// 0x801D49E0 PCTTarget::get_cell_info_at_gridindex(unsigned int) const (76B)
// TRIAGE

struct CellInfo { char data[24]; };

class PCTTarget {
public:
    char pad_000[188];
    CellInfo* m_cells;
    int       m_count;
    void* get_cell_info_at_gridindex(unsigned int idx) const;
    int  get_cell_info_array_index(unsigned int idx) const;
};

void* PCTTarget::get_cell_info_at_gridindex(unsigned int idx) const {
    int i = get_cell_info_array_index(idx);
    if ((unsigned int)i >= (unsigned int)m_count) return 0;
    return (char*)m_cells + i * 24;
}
