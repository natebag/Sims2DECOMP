// 0x802269F8 (8 bytes)
class InteractorModule {
public:
    class WallPainter {
    public:
        int GetAnchorPos();
    };
};

int InteractorModule::WallPainter::GetAnchorPos() {
    return (int)((char*)this + 0x60);
}
