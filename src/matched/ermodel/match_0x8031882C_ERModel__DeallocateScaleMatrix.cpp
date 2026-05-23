/* ERModel::DeallocateScaleMatrix(void) at 0x8031882C (72B) */

extern void ERModel_free(void *, void *);
extern char g_allocator[16];

struct ERModelDSM {
    char pad[0x174];
    void *m_scaleMatrix;
    void DeallocateScaleMatrix(void);
};

void ERModelDSM::DeallocateScaleMatrix(void) {
    void *matrix = m_scaleMatrix;
    if (matrix != 0) {
        ERModel_free(g_allocator, matrix);
        m_scaleMatrix = 0;
    }
}
