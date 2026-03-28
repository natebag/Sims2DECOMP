struct ERModel {
    char _p[0x11c];
    char *m_dummies;
    void *GetDummy(int i);
};
void *ERModel::GetDummy(int i) { return m_dummies + i * 0x58; }
