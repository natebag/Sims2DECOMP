// 0x80205040 InteractorModule::DirectInteractor::Draw(InteractorVisualizer&) (44B)
// Arg-swap thunk
struct DirectInteractor;
struct InteractorVisualizer;

extern void DirectInteractor__DrawImpl(InteractorVisualizer& vis, DirectInteractor* self);

void DirectInteractor__Draw(DirectInteractor* self, InteractorVisualizer& vis) {
    DirectInteractor__DrawImpl(vis, self);
}
