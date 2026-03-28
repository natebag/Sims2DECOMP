// 0x802095D4 (8 bytes)
class InteractorModule {
public:
    class Interactor {
    public:
        void SetDrawState(int p);
    };
};

void InteractorModule::Interactor::SetDrawState(int p) {
    *(int*)((char*)this + 0x4C) = p;
}
