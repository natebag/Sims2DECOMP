// 0x80219488 InteractorModule::ObjectManipulator::PreDraw(InteractorVisualizer&) (44B)
// Arg-swap thunk
struct ObjectManipulator;
struct InteractorVisualizer;

extern void ObjectManipulator__PreDrawImpl(InteractorVisualizer& vis, ObjectManipulator* self);

void ObjectManipulator__PreDraw(ObjectManipulator* self, InteractorVisualizer& vis) {
    ObjectManipulator__PreDrawImpl(vis, self);
}
