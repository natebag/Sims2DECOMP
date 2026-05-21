// 0x80217388 InteractorModule::InteractorVisualizer::SetupDrawCallback(EHouse *, int) (96B)
// Gets player interactor via InteractorManager singleton, then MI-vcall via secondary
// vtable at interactor+92 (offsets 0xB0/0xB4). EHouse* param is unused.

struct EHouse;

namespace InteractorModule {
    enum InteractorType { kInteractorTypeAny = -1 };

    struct Interactor;

    class InteractorManager {
    public:
        static InteractorManager* GetSingleton();
        Interactor* GetPlayerInteractor(int playerIndex, InteractorType type);
    };

    class InteractorVisualizer {
    public:
        void SetupDrawCallback(EHouse* pHouse, int playerIndex);
    };
}

void InteractorModule::InteractorVisualizer::SetupDrawCallback(EHouse*, int playerIndex) {
    Interactor* interactor = InteractorManager::GetSingleton()->GetPlayerInteractor(playerIndex, kInteractorTypeAny);
    if (!interactor) return;
    char* vt = *(char**)((char*)interactor + 92);
    short thisAdj = *(short*)(vt + 0xB0);
    void (*fn)(void*, InteractorVisualizer*) =
        *(void(**)(void*, InteractorVisualizer*))(vt + 0xB4);
    fn((char*)interactor + thisAdj, this);
}
