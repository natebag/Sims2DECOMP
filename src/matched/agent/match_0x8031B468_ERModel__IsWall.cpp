struct ERModel {
    char _pad[0x30];
    int m_val;
    int IsWall();
};
int ERModel::IsWall() { return m_val; }
