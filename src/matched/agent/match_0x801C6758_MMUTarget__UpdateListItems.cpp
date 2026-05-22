// 0x801C6758 MMUTarget::UpdateListItems() (68B)

class MMUTarget {
public:
    char pad[0x8C];
    int m_8C;
    void UpdateNGHListItems();
    void UpdateLotListItems();
    void UpdateListItems();
};

void MMUTarget::UpdateListItems() {
    int mode = m_8C;
    if (mode == 0) goto ngh;
    if (mode != 1) goto check_lot;
ngh:
    UpdateNGHListItems();
    return;
check_lot:
    if (mode == 2) UpdateLotListItems();
}
