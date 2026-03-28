// 0x802092AC (8 bytes)
class InteractorModule {
public:
    class Interactor {
    public:
        int GetAttachedCamera();
    };
};

int InteractorModule::Interactor::GetAttachedCamera() {
    return *(int*)((char*)this + 0x4);
}
