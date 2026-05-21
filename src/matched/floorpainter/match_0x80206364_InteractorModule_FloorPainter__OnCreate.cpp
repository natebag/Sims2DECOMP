// 0x80206364 InteractorModule::FloorPainter::OnCreate(void) (116B)
// GetVisualizer()->CreateResources(*this); store 1.0f+0.1f; count=arr[-1] if arr; new int[count].

struct FPOCGlobals {
    char pad[0xD4];
    struct { void* m_arr; } *m_floorContainer;
};

extern "C" FPOCGlobals _globals;

namespace InteractorModule {
    class FloorPainter;
    class InteractorVisualizer {
    public:
        void CreateResources(FloorPainter& painter);
    };
    class InteractorManager {
    public:
        static InteractorVisualizer* GetVisualizer();
    };
    class FloorPainter {
    public:
        char _pad0[80];
        float m_field80;
        float m_field84;
        char _pad58[96];
        void* m_resource;
        void OnCreate();
    };
}

void InteractorModule::FloorPainter::OnCreate() {
    InteractorManager::GetVisualizer()->CreateResources(*this);
    m_field80 = 1.0f;
    m_field84 = 0.1f;
    int count = 0;
    void* arr = _globals.m_floorContainer->m_arr;
    if (arr)
        count = ((int*)arr)[-1];
    m_resource = new int[count];
}
