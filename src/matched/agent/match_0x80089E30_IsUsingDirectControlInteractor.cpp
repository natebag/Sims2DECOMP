// IsUsingDirectControlInteractor(int) @ 0x80089E30 (100B)

namespace InteractorModule {
    enum InteractorType { kDirect = -1, kDefault = 0 };
    struct Interactor {};
    struct InteractorManager {
        static InteractorManager* GetSingleton();
        Interactor* GetPlayerInteractor(int idx, InteractorType type);
    };
}

int IsUsingDirectControlInteractor(int idx) {
    using namespace InteractorModule;
    InteractorManager* mgr = InteractorManager::GetSingleton();
    Interactor* p1 = mgr->GetPlayerInteractor(idx, (InteractorType)-1);
    if (p1 == 0) return 0;
    mgr = InteractorManager::GetSingleton();
    Interactor* p2 = mgr->GetPlayerInteractor(idx, (InteractorType)0);
    return p1 == p2;
}
