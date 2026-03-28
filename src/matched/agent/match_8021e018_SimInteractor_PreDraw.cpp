void PreDraw_SI_impl(void *vis, void *interactor);

struct SimInteractor_PreDraw_S {
    void PreDraw(void *visualizer);
};

void SimInteractor_PreDraw_S::PreDraw(void *visualizer) {
    PreDraw_SI_impl(visualizer, this);
}
