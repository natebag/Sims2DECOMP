// 0x8020B6A0 (8 bytes)
class InteractorModule {
public:
    class InteractorManager {
    public:
        int IsInitialized();
    };
};

int InteractorModule::InteractorManager::IsInitialized() {
    return *(int*)((char*)this + 0x0);
}
