typedef void *IntMgr;

IntMgr FP_GetInteractorManagerA();
void FP_DestroyVisualizerA(IntMgr mgr, void *self);
void FP_ReleaseShaderA(void *shader);

struct FloorPainter_D {
    char pad[0xB8];
    void *m_shader;

    void OnDestroy();
};

void FloorPainter_D::OnDestroy() {
    IntMgr mgr = FP_GetInteractorManagerA();
    FP_DestroyVisualizerA(mgr, this);
    if (m_shader != 0) {
        FP_ReleaseShaderA(m_shader);
    }
    m_shader = 0;
}
