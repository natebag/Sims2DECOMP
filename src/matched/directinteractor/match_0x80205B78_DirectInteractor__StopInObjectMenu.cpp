// 0x80205B78 InteractorModule::DirectInteractor::StopInObjectMenu(void) (56B)
struct DirectInteractor;

extern char g_interactorGlobalPtrHolder[64];  // non-SDA

extern void InteractorModule__ProcessStopInObjectMenu(void* g, void* arg);

void DirectInteractor__StopInObjectMenu(DirectInteractor* self) {
    void* g = *(void**)g_interactorGlobalPtrHolder;
    if (g != 0) {
        InteractorModule__ProcessStopInObjectMenu(g, *(void**)self);
    }
}
