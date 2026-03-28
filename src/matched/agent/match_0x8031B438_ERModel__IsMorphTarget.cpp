struct ERModel {
    char _pad[0x38];
    int m_val;
    int IsMorphTarget();
};
int ERModel::IsMorphTarget() { return m_val; }
