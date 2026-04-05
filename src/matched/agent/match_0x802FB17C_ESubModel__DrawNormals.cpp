void ESM_DrawNormalsFn(void *, void *);

struct ESM_DN {
    void *m_array;
    int m_count;
    void DrawNormals(void *erc);
};

void ESM_DN::DrawNormals(void *erc) {
    for (int i = 0; i < m_count; i++) {
        ESM_DrawNormalsFn((char *)m_array + i * 112, erc);
    }
}
