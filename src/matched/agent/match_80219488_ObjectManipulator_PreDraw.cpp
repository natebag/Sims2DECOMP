void PreDraw_OM_impl(void *vis, void *interactor);

struct ObjectManipulator_PreDraw_S {
    void PreDraw(void *visualizer);
};

void ObjectManipulator_PreDraw_S::PreDraw(void *visualizer) {
    PreDraw_OM_impl(visualizer, this);
}
