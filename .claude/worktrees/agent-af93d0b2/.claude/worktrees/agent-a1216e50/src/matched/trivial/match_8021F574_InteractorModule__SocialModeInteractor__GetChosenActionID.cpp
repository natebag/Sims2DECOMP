// 0x8021F574 (8 bytes)
class InteractorModule {
public:
    class SocialModeInteractor {
    public:
        short GetChosenActionID();
    };
};

short InteractorModule::SocialModeInteractor::GetChosenActionID() {
    return *(short*)((char*)this + 0x60);
}
