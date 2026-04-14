// 0x80203E38 InteractorModule::DirectInteractor::OnDestroy(void) (52B)

struct InteractorModule_InteractorVisualizer;
extern InteractorModule_InteractorVisualizer* GetVisualizer__23InteractorModule_InteractorManager(void);
extern void DestroyResources__26InteractorModule_InteractorVisualizerR33InteractorModule_DirectInteractor(InteractorModule_InteractorVisualizer*, struct InteractorModule_DirectInteractor&);

struct InteractorModule_DirectInteractor {
    void OnDestroy(void);
};

void InteractorModule_DirectInteractor::OnDestroy(void) {
    InteractorModule_InteractorVisualizer* viz = GetVisualizer__23InteractorModule_InteractorManager();
    DestroyResources__26InteractorModule_InteractorVisualizerR33InteractorModule_DirectInteractor(viz, *this);
}
