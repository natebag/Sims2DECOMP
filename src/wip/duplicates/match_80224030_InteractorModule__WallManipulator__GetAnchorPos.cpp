// 0x80224030 (8 bytes)
class InteractorModule {
public:
    class WallManipulator {
    public:
        int GetAnchorPos();
    };
};

int InteractorModule::WallManipulator::GetAnchorPos() {
    return (int)((char*)this + 0x60);
}
