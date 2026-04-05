void ESM_DelRefFn(void *);

struct ESM_DR {
    void *m_array;
    int m_count;
    void DelRefSubResources(void);
};

void ESM_DR::DelRefSubResources(void) {
    for (int i = 0; i < m_count; i++) {
        ESM_DelRefFn((char *)m_array + i * 112);
    }
}
