void Draw_OM_impl(void *vis, void *interactor);

struct ObjectManipulator_Draw_S {
    void Draw(void *visualizer);
};

void ObjectManipulator_Draw_S::Draw(void *visualizer) {
    Draw_OM_impl(visualizer, this);
}
