void IV_Release(void *);

struct IV_ShutdownS {
    void *m_res0;
    void *m_res1;
    void Shutdown(void);
};

void IV_ShutdownS::Shutdown(void) {
    IV_Release(m_res0);
    m_res0 = 0;
    IV_Release(m_res1);
    m_res1 = 0;
}
