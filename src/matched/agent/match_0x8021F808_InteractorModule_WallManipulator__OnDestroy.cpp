// 0x8021F808 InteractorModule::WallManipulator::OnDestroy(void) (44B)
struct WallManipulator;
struct InteractorManager;

extern InteractorManager* InteractorManager__GetSingleton();
extern void InteractorManager__UnregisterWall(InteractorManager* mgr, WallManipulator* self);

void WallManipulator__OnDestroy(WallManipulator* self) {
    InteractorManager__UnregisterWall(InteractorManager__GetSingleton(), self);
}
