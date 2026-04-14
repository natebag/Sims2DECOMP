// 0x802191F0 InteractorModule::ObjectManipulator::OnStop(void) (60B)
struct ObjectManipulator {
    int m_id;
};
struct InteractorManager;

extern void InteractorModule__ClearCameraFilter(int id);
extern InteractorManager* InteractorManager__GetSingletonAlt();
extern void InteractorManager__CloseSession(InteractorManager* mgr, int id);

void ObjectManipulator__OnStop(ObjectManipulator* self) {
    InteractorModule__ClearCameraFilter(self->m_id);
    InteractorManager__CloseSession(InteractorManager__GetSingletonAlt(), self->m_id);
}
