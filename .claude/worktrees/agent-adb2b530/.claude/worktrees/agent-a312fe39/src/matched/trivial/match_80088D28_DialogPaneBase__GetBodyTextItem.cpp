// 0x80088D28 (8 bytes)
class DialogPaneBase {
public:
    int GetBodyTextItem();
};

int DialogPaneBase::GetBodyTextItem() {
    return *(int*)((char*)this + 0x64);
}
