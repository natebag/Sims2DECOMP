// 0x80087B1C (8 bytes)
class WrapperPaneBase {
public:
    int GetState();
};

int WrapperPaneBase::GetState() {
    return *(int*)((char*)this + 0x34);
}
