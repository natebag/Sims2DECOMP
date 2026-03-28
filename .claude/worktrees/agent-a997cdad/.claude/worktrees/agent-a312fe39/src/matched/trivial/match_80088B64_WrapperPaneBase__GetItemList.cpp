// 0x80088B64 (8 bytes)
class WrapperPaneBase {
public:
    int GetItemList();
};

int WrapperPaneBase::GetItemList() {
    return (int)((char*)this + 0x8);
}
