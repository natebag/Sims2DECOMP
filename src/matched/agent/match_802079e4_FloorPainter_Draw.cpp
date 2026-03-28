void Draw_FP_impl(void *vis, void *interactor);

struct FloorPainter_Draw_S {
    void Draw(void *visualizer);
};

void FloorPainter_Draw_S::Draw(void *visualizer) {
    Draw_FP_impl(visualizer, this);
}
