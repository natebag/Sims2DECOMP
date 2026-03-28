// 0x8020612C (8 bytes)
class InteractorModule {
public:
    class DirectInteractor {
    public:
        int IsAutonomous();
    };
};

int InteractorModule::DirectInteractor::IsAutonomous() {
    return *(int*)((char*)this + 0x80);
}
