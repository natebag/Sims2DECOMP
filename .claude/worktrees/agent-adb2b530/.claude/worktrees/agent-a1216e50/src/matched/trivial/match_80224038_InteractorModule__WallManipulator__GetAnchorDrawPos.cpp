// 0x80224038 (8 bytes)
class InteractorModule {
public:
    class WallManipulator {
    public:
        int GetAnchorDrawPos();
    };
};

int InteractorModule::WallManipulator::GetAnchorDrawPos() {
    return (int)((char*)this + 0x6C);
}
