struct ERModel {
    char _pad[0x20];
    int m_val;
    int IsWeldable();
};
int ERModel::IsWeldable() { return m_val; }
