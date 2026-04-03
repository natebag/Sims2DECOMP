// 0x80088D20 (8 bytes)
class DialogPaneBase {
public:
    int GetTitleTextItem();
};

int DialogPaneBase::GetTitleTextItem() {
    return *(int*)((char*)this + 0x60);
}
