// 0x8021E044 InteractorModule::SimInteractor::Draw(InteractorVisualizer&) (44B)
// Arg-swap thunk
struct SimInteractor;
struct InteractorVisualizer;

extern void SimInteractor__DrawImpl(InteractorVisualizer& vis, SimInteractor* self);

void SimInteractor__Draw(SimInteractor* self, InteractorVisualizer& vis) {
    SimInteractor__DrawImpl(vis, self);
}
