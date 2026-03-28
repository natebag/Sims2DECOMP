// 0x8021F590 (8 bytes)
class InteractorModule {
public:
    class SocialModeInteractor {
    public:
        void SetTimout(int p);
    };
};

void InteractorModule::SocialModeInteractor::SetTimout(int p) {
    *(int*)((char*)this + 0x6C) = p;
}
