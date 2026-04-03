// 0x8008879C (8 bytes)
class WrapperPaneBase {
public:
    int GetDeclineButton();
};

int WrapperPaneBase::GetDeclineButton() {
    return *(int*)((char*)this + 0x44);
}
