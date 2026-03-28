// 0x8020952C (8 bytes)
class InteractorModule {
public:
    class Interactor {
    public:
        int GetSnappedPos();
    };
};

int InteractorModule::Interactor::GetSnappedPos() {
    return (int)((char*)this + 0x20);
}
