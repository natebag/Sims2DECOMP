struct ESRM_Ctor {
    int m_field0;
    int m_field4;
    int m_field8;

    void ctor(void);
};

void ESRM_Ctor::ctor(void) {
    m_field4 = 0;
    m_field8 = 1;
    m_field0 = 0;
}
