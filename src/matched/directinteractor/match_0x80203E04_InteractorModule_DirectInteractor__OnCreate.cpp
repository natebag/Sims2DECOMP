// 0x80203E04 InteractorModule::DirectInteractor::OnCreate(void) (52B)
struct DirectInteractor;
struct InteractorManager;

extern InteractorManager* InteractorManager__GetSingleton();
extern void InteractorManager__Register(InteractorManager* mgr, DirectInteractor* self);

void DirectInteractor__OnCreate(DirectInteractor* self) {
    InteractorManager__Register(InteractorManager__GetSingleton(), self);
}
