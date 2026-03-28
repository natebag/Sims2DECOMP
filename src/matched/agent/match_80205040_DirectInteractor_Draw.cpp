void Draw_DI_impl(void *vis, void *interactor);

struct DirectInteractor_Draw_S {
    void Draw(void *visualizer);
};

void DirectInteractor_Draw_S::Draw(void *visualizer) {
    Draw_DI_impl(visualizer, this);
}
