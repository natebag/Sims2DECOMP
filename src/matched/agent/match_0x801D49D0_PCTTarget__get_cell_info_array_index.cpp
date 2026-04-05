/* PCTTarget::get_cell_info_array_index(unsigned int) const at 0x801D49D0 (16B) */

struct PCTTarget {
    char pad[0xB4];
    int m_fieldB4;

    unsigned int get_cell_info_array_index(unsigned int index) const;
};

unsigned int PCTTarget::get_cell_info_array_index(unsigned int index) const {
    return m_fieldB4 * 6 + index;
}
