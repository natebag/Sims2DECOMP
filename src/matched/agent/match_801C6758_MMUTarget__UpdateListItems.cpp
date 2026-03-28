/* MMUTarget::UpdateListItems(void) at 0x801C6758 (68B) */

struct MMUTarget {
    char pad_000[0x8C];
    int m_field8C;

    void UpdateListItems();
    void UpdateNGHListItems();
    void UpdateLotListItems();
};

void MMUTarget::UpdateListItems() {
    int mode = m_field8C;
    if (mode == 0) {
        UpdateNGHListItems();
    } else if (mode == 1) {
        UpdateNGHListItems();
    } else if (mode == 2) {
        UpdateLotListItems();
    }
}
