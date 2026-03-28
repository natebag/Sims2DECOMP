struct ERModel {
    char _pad[0x34];
    int m_val;
    int IsLattice();
};
int ERModel::IsLattice() { return m_val; }
