struct SimpleReconObject_OptionsRecon {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_OptionsRecon::GetType() { return m_type; }
