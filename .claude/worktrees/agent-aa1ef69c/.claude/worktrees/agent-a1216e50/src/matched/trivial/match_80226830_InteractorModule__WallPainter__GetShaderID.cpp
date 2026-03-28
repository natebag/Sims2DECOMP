// 0x80226830 (8 bytes)
class InteractorModule {
public:
    class WallPainter {
    public:
        int GetShaderID();
    };
};

int InteractorModule::WallPainter::GetShaderID() {
    return *(int*)((char*)(*(int*)((char*)this + 0x90)) + 0x8);
}
