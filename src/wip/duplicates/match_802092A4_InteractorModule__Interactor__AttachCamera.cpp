// 0x802092A4 (8 bytes)
class InteractorModule {
public:
    class Interactor {
    public:
        void AttachCamera(int p);
    };
};

void InteractorModule::Interactor::AttachCamera(int p) {
    *(int*)((char*)this + 0x4) = p;
}
