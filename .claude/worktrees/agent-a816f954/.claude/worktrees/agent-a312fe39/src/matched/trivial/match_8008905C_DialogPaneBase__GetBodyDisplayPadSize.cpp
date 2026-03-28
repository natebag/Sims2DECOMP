// 0x8008905C (8 bytes)
class DialogPaneBase {
public:
    int GetBodyDisplayPadSize();
};

int DialogPaneBase::GetBodyDisplayPadSize() {
    return (int)((char*)(*(int*)((char*)this + 0x64)) + 0x34);
}
