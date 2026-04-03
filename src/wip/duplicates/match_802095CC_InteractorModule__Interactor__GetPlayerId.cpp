// 0x802095CC (8 bytes)
class InteractorModule {
public:
    class Interactor {
    public:
        int GetPlayerId();
    };
};

int InteractorModule::Interactor::GetPlayerId() {
    return *(int*)((char*)this + 0x0);
}
