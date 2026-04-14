// 0x8021F448 InteractorModule::SocialModeInteractor::Draw(InteractorVisualizer&) (44B)
// Arg-swap thunk
struct SocialModeInteractor;
struct InteractorVisualizer;

extern void SocialModeInteractor__DrawImpl(InteractorVisualizer& vis, SocialModeInteractor* self);

void SocialModeInteractor__Draw(SocialModeInteractor* self, InteractorVisualizer& vis) {
    SocialModeInteractor__DrawImpl(vis, self);
}
