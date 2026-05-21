// 0x800159A0 {anonymous}::IsUsingSpecifiedInteractor(int, InteractorModule::InteractorType) (104B)
// Gets current interactor (type=-1) and specified-type interactor via same GetSingleton chain.
// Returns (current == specified) using xor+subfic+adde equality boolification.

namespace InteractorModule {
    enum InteractorType { kInteractorTypeAny = -1 };

    struct Interactor;

    class InteractorManager {
    public:
        static InteractorManager* GetSingleton();
        Interactor* GetPlayerInteractor(int playerIndex, InteractorType type);
    };
}

namespace {
    int IsUsingSpecifiedInteractor(int playerIndex, InteractorModule::InteractorType type) {
        using namespace InteractorModule;
        Interactor* current = InteractorManager::GetSingleton()->GetPlayerInteractor(playerIndex, kInteractorTypeAny);
        if (!current) return 0;
        Interactor* specified = InteractorManager::GetSingleton()->GetPlayerInteractor(playerIndex, type);
        return current == specified;
    }
}
