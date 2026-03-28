// 0x80209524 (8 bytes)
class InteractorModule {
public:
    class Interactor {
    public:
        int GetPos();
    };
};

int InteractorModule::Interactor::GetPos() {
    return (int)((char*)this + 0x8);
}
