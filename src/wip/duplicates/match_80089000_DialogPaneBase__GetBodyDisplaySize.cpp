// 0x80089000 (8 bytes)
class DialogPaneBase {
public:
    int GetBodyDisplaySize();
};

int DialogPaneBase::GetBodyDisplaySize() {
    return (int)((char*)(*(int*)((char*)this + 0x64)) + 0x2C);
}
