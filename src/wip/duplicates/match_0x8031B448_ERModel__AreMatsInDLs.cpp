struct ERModel {
    char _pad[0x8c];
    int m_val;
    int AreMatsInDLs();
};
int ERModel::AreMatsInDLs() { return m_val; }
