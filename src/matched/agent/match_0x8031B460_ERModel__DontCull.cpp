struct ERModel {
    char _pad[0x2c];
    int m_val;
    int DontCull();
};
int ERModel::DontCull() { return m_val; }
