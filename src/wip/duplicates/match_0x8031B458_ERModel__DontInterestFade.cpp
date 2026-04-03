struct ERModel {
    char _pad[0x28];
    int m_val;
    int DontInterestFade();
};
int ERModel::DontInterestFade() { return m_val; }
