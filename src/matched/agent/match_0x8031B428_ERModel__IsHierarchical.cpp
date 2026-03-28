struct ERModel {
    char _pad[0x14];
    int m_val;
    int IsHierarchical();
};
int ERModel::IsHierarchical() { return m_val; }
