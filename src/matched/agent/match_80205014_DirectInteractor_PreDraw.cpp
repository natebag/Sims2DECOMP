void PreDraw_DI_impl(void *vis, void *interactor);

struct DirectInteractor_PreDraw_S {
    void PreDraw(void *visualizer);
};

void DirectInteractor_PreDraw_S::PreDraw(void *visualizer) {
    PreDraw_DI_impl(visualizer, this);
}
