// 0x8020919C (8 bytes)
class InteractorModule {
public:
    class FloorPainter {
    public:
        int GetSelectedFloorData();
    };
};

int InteractorModule::FloorPainter::GetSelectedFloorData() {
    return (int)((char*)this + 0x94);
}
