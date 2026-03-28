void Draw_SM_impl(void *vis, void *interactor);

struct SocialModeInteractor_Draw_S {
    void Draw(void *visualizer);
};

void SocialModeInteractor_Draw_S::Draw(void *visualizer) {
    Draw_SM_impl(visualizer, this);
}
