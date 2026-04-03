// 0x80206118 (8 bytes)
class InteractorModule {
public:
    class DirectInteractor {
    public:
        int GetControlStatus();
    };
};

int InteractorModule::DirectInteractor::GetControlStatus() {
    return *(int*)((char*)this + 0x64);
}
