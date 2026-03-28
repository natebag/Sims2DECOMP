// 0x80209194 (8 bytes)
class InteractorModule {
public:
    class FloorPainter {
    public:
        int GetAnchorPos();
    };
};

int InteractorModule::FloorPainter::GetAnchorPos() {
    return (int)((char*)this + 0x64);
}
