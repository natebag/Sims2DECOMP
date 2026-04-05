void ESM_ApplyMorphFn(void *);

struct ESM_AM {
    void *m_array;
    int m_count;
    int ApplyMorph(void);
};

int ESM_AM::ApplyMorph(void) {
    for (int i = 0; i < m_count; i++) {
        ESM_ApplyMorphFn((char *)m_array + i * 112);
    }
    return 1;
}
