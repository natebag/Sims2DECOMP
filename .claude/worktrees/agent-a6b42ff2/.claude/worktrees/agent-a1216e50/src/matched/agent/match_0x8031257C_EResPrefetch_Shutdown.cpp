void ShutdownInternal(void);
void DestroyContainer(void*);
void DestroyOther(void*);

struct EResPrefetch {
    char pad0[8];
    char m_container[900];
    char m_other[76];
    int m_state;

    void Shutdown(void);
};

void EResPrefetch::Shutdown(void) {
    ShutdownInternal();
    DestroyContainer(&m_container);
    DestroyOther(&m_other);
    m_state = 0;
}
