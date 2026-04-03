// 0x80226A00 (8 bytes)
class InteractorModule {
public:
    class WallPainter {
    public:
        int GetAnchorDrawPos();
    };
};

int InteractorModule::WallPainter::GetAnchorDrawPos() {
    return (int)((char*)this + 0x6C);
}
