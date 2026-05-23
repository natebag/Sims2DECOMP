// 0x80205FB4 InteractorModule::DirectInteractor::SetAutonomous(void) (64B)
struct DirectInteractor {
    char pad[128];
    int m_autonomous;
};

extern char g_interactorGlobalPtrHolder[64];  // non-SDA (addr 0x80475BC8)

extern void InteractorModule__ProcessAutonomous(void* g, void* arg);

void DirectInteractor__SetAutonomous(DirectInteractor* self) {
    self->m_autonomous = 1;
    void* g = *(void**)g_interactorGlobalPtrHolder;
    if (g != 0) {
        InteractorModule__ProcessAutonomous(g, *(void**)self);
    }
}
