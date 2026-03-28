void Draw_SI_impl(void *vis, void *interactor);

struct SimInteractor_Draw_S {
    void Draw(void *visualizer);
};

void SimInteractor_Draw_S::Draw(void *visualizer) {
    Draw_SI_impl(visualizer, this);
}
