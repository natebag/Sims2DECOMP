// 0x8021F588 (8 bytes)
class InteractorModule {
public:
    class SocialModeInteractor {
    public:
        int GetTimout();
    };
};

int InteractorModule::SocialModeInteractor::GetTimout() {
    return *(int*)((char*)this + 0x6C);
}
