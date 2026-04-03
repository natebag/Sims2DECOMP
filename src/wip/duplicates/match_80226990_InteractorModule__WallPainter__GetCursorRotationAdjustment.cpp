// 0x80226990 (8 bytes)
class InteractorModule {
public:
    class WallPainter {
    public:
        float GetCursorRotationAdjustment();
    };
};

float InteractorModule::WallPainter::GetCursorRotationAdjustment() {
    return *(float*)((char*)this + 0x84);
}
