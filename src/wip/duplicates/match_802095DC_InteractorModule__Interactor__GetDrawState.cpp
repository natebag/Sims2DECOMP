// 0x802095DC (8 bytes)
class InteractorModule {
public:
    class Interactor {
    public:
        int GetDrawState();
    };
};

int InteractorModule::Interactor::GetDrawState() {
    return *(int*)((char*)this + 0x4C);
}
