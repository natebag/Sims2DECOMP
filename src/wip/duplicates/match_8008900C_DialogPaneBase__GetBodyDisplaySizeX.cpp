// 0x8008900C (8 bytes)
class DialogPaneBase {
public:
    float GetBodyDisplaySizeX();
};

float DialogPaneBase::GetBodyDisplaySizeX() {
    return *(float*)((char*)(*(int*)((char*)this + 0x64)) + 0x2C);
}
