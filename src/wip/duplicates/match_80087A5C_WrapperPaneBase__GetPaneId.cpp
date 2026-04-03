// 0x80087A5C (8 bytes)
class WrapperPaneBase {
public:
    int GetPaneId();
};

int WrapperPaneBase::GetPaneId() {
    return *(int*)((char*)this + 0x0);
}
