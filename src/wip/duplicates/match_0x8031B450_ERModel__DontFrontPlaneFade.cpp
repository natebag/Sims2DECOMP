struct ERModel {
    char _pad[0x24];
    int m_val;
    int DontFrontPlaneFade();
};
int ERModel::DontFrontPlaneFade() { return m_val; }
