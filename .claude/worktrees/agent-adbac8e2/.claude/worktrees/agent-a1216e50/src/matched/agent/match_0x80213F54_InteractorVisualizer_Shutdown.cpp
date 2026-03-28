void FreeResource(void*);

struct InteractorVisualizer {
    void* m_res0;
    void* m_res1;

    void Shutdown(void);
};

void InteractorVisualizer::Shutdown(void) {
    FreeResource(m_res0);
    m_res0 = 0;
    FreeResource(m_res1);
    m_res1 = 0;
}
