// 0x8021F41C InteractorModule::SocialModeInteractor::PreDraw(InteractorVisualizer&) (44B)
// Arg-swap thunk
struct SocialModeInteractor;
struct InteractorVisualizer;

extern void SocialModeInteractor__PreDrawImpl(InteractorVisualizer& vis, SocialModeInteractor* self);

void SocialModeInteractor__PreDraw(SocialModeInteractor* self, InteractorVisualizer& vis) {
    SocialModeInteractor__PreDrawImpl(vis, self);
}
