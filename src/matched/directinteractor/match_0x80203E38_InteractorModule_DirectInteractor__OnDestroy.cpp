// 0x80203E38 InteractorModule::DirectInteractor::OnDestroy(void) (52B)
struct DirectInteractor;
struct InteractorManager;

extern InteractorManager* InteractorManager__GetSingleton();
extern void InteractorManager__Unregister(InteractorManager* mgr, DirectInteractor* self);

void DirectInteractor__OnDestroy(DirectInteractor* self) {
    InteractorManager__Unregister(InteractorManager__GetSingleton(), self);
}
