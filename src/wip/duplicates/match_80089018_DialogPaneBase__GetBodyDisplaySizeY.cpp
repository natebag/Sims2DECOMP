// 0x80089018 (8 bytes)
class DialogPaneBase {
public:
    float GetBodyDisplaySizeY();
};

float DialogPaneBase::GetBodyDisplaySizeY() {
    return *(float*)((char*)(*(int*)((char*)this + 0x64)) + 0x30);
}
