// 0x8022448C InteractorModule::WallPainter::OnStop(void) (60B)
struct WallPainter {
    int m_id;
};
struct InteractorManager;

extern void InteractorModule__ClearCameraFilter(int id);
extern InteractorManager* InteractorManager__GetSingletonAlt();
extern void InteractorManager__CloseSession(InteractorManager* mgr, int id);

void WallPainter__OnStop(WallPainter* self) {
    InteractorModule__ClearCameraFilter(self->m_id);
    InteractorManager__CloseSession(InteractorManager__GetSingletonAlt(), self->m_id);
}
