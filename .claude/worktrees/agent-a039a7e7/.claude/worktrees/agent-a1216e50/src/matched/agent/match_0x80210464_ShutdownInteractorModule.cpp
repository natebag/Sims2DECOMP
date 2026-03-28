struct PlayerObj {
    void Setup(int, int);
};

PlayerObj* GetPlayer(void);

struct InteractorMgr {
    void Shutdown(void);
};

InteractorMgr* GetSingleton(void);

namespace InteractorModule {
void ShutdownInteractorModule(void) {
    GetPlayer()->Setup(0, 0);
    GetPlayer()->Setup(1, 0);
    GetSingleton()->Shutdown();
}
}
