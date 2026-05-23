// 0x802194B4 InteractorModule::ObjectManipulator::Draw(InteractorVisualizer&) (44B)
// Arg-swap thunk
struct ObjectManipulator;
struct InteractorVisualizer;

extern void ObjectManipulator__DrawImpl(InteractorVisualizer& vis, ObjectManipulator* self);

void ObjectManipulator__Draw(ObjectManipulator* self, InteractorVisualizer& vis) {
    ObjectManipulator__DrawImpl(vis, self);
}
