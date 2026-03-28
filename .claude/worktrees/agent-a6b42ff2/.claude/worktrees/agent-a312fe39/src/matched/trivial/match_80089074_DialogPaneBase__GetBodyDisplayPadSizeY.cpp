// 0x80089074 (8 bytes)
class DialogPaneBase {
public:
    float GetBodyDisplayPadSizeY();
};

float DialogPaneBase::GetBodyDisplayPadSizeY() {
    return *(float*)((char*)(*(int*)((char*)this + 0x64)) + 0x38);
}
