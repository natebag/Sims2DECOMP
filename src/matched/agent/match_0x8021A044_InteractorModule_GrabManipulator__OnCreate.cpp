// 0x8021A044 InteractorModule::GrabManipulator::OnCreate(void) (44B)
struct GrabManipulator;
struct ObjectManipulator;

extern void ObjectManipulator__OnCreate(ObjectManipulator* self);
extern char GrabManipulator_vtable[64];  // forced non-SDA via >8 byte size

void GrabManipulator__OnCreate(GrabManipulator* self) {
    ObjectManipulator__OnCreate((ObjectManipulator*)self);
    *(void**)((char*)self + 96) = (void*)GrabManipulator_vtable;
}
