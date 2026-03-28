// 0x80088200 (8 bytes)
class WrapperPaneBase {
public:
    int GetBackgroundShader();
};

int WrapperPaneBase::GetBackgroundShader() {
    return *(int*)((char*)this + 0x18);
}
