// 0x8021E018 InteractorModule::SimInteractor::PreDraw(InteractorVisualizer&) (44B)
// Arg-swap thunk
struct SimInteractor;
struct InteractorVisualizer;

extern void SimInteractor__PreDrawImpl(InteractorVisualizer& vis, SimInteractor* self);

void SimInteractor__PreDraw(SimInteractor* self, InteractorVisualizer& vis) {
    SimInteractor__PreDrawImpl(vis, self);
}
