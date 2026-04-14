// 0x80203E04 InteractorModule::DirectInteractor::OnCreate(void) (52B)

struct InteractorModule_InteractorVisualizer;
extern InteractorModule_InteractorVisualizer* GetVisualizer__23InteractorModule_InteractorManager(void);
extern void CreateResources__26InteractorModule_InteractorVisualizerR33InteractorModule_DirectInteractor(InteractorModule_InteractorVisualizer*, struct InteractorModule_DirectInteractor&);

struct InteractorModule_DirectInteractor {
    void OnCreate(void);
};

void InteractorModule_DirectInteractor::OnCreate(void) {
    InteractorModule_InteractorVisualizer* viz = GetVisualizer__23InteractorModule_InteractorManager();
    CreateResources__26InteractorModule_InteractorVisualizerR33InteractorModule_DirectInteractor(viz, *this);
}
