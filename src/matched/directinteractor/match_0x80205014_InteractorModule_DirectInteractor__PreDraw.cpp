// 0x80205014 InteractorModule::DirectInteractor::PreDraw(InteractorVisualizer&) (44B)
// Arg-swap thunk: delegates to impl with (vis, this) instead of (this, vis)
struct DirectInteractor;
struct InteractorVisualizer;

extern void DirectInteractor__PreDrawImpl(InteractorVisualizer& vis, DirectInteractor* self);

void DirectInteractor__PreDraw(DirectInteractor* self, InteractorVisualizer& vis) {
    DirectInteractor__PreDrawImpl(vis, self);
}
