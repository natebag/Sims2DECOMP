struct InteractorVisualizer {
    void CreateResources(void*);
};

InteractorVisualizer* InteractorManager_GetVisualizer();

struct WallPainter {
    char pad_00[0x50];
    float m_field50;
    float m_field54;

    void OnCreate();
};

void WallPainter::OnCreate() {
    InteractorVisualizer* vis = InteractorManager_GetVisualizer();
    vis->CreateResources(this);
    m_field50 = 0.5f;
    m_field54 = 3.0f;
}
