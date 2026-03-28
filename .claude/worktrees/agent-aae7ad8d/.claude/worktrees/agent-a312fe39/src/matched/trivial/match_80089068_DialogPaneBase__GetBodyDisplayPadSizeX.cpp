// 0x80089068 (8 bytes)
class DialogPaneBase {
public:
    float GetBodyDisplayPadSizeX();
};

float DialogPaneBase::GetBodyDisplayPadSizeX() {
    return *(float*)((char*)(*(int*)((char*)this + 0x64)) + 0x34);
}
