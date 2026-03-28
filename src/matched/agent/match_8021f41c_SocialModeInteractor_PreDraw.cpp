void PreDraw_SM_impl(void *vis, void *interactor);

struct SocialModeInteractor_PreDraw_S {
    void PreDraw(void *visualizer);
};

void SocialModeInteractor_PreDraw_S::PreDraw(void *visualizer) {
    PreDraw_SM_impl(visualizer, this);
}
