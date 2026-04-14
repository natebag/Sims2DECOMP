// 0x8021A188 InteractorModule::PlaceManipulator::OnCreate(void) (44B)
struct PlaceManipulator;
struct ObjectManipulator;

extern void ObjectManipulator__OnCreate(ObjectManipulator* self);
extern char PlaceManipulator_vtable[64];  // non-SDA

void PlaceManipulator__OnCreate(PlaceManipulator* self) {
    ObjectManipulator__OnCreate((ObjectManipulator*)self);
    *(void**)((char*)self + 96) = (void*)PlaceManipulator_vtable;
}
