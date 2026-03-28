// 0x802091A4 (8 bytes)
class InteractorModule {
public:
    class FloorPainter {
    public:
        int IsInPlaceMode();
    };
};

int InteractorModule::FloorPainter::IsInPlaceMode() {
    return *(int*)((char*)this + 0xA4);
}
