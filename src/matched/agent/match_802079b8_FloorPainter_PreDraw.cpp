void PreDraw_FP_impl(void *vis, void *interactor);

struct FloorPainter_PreDraw_S {
    void PreDraw(void *visualizer);
};

void FloorPainter_PreDraw_S::PreDraw(void *visualizer) {
    PreDraw_FP_impl(visualizer, this);
}
