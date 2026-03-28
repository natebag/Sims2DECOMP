// 0x80226A08 (8 bytes)
class InteractorModule {
public:
    class WallPainter {
    public:
        int GetHoldPos();
    };
};

int InteractorModule::WallPainter::GetHoldPos() {
    return (int)((char*)this + 0x78);
}
