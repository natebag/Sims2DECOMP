struct ERModel {
    char _pad[0x114];
    int m_latticeCount;
    int GetLatticeCount();
};
int ERModel::GetLatticeCount() { return m_latticeCount; }
