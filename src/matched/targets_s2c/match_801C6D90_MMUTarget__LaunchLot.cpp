/* MMUTarget::LaunchLot(int) at 0x801C6D90 (96B) */

struct MMUTarget {
    char pad_000[0x8C];
    int m_field8C;
    char pad_090[0x98 - 0x90];
    int m_field98;

    void LaunchLot(int lot);
    void EnterLot(int lot);
    void UpdateNGHListItems();
    void UpdateLotListItems();
};

void MMUTarget::LaunchLot(int lot) {
    int enterLot;
    if (lot != -1) {
        enterLot = lot + 1;
    } else {
        enterLot = m_field98 + 1;
    }
    EnterLot(enterLot);
    m_field8C = 0;
    UpdateNGHListItems();
    UpdateLotListItems();
}
