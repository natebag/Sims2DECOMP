// 0x800885B8 (8 bytes)
class WrapperPaneBase {
public:
    int GetAcceptButton();
};

int WrapperPaneBase::GetAcceptButton() {
    return *(int*)((char*)this + 0x40);
}
