// 0x80088980 (8 bytes)
class WrapperPaneBase {
public:
    int GetAlt1Button();
};

int WrapperPaneBase::GetAlt1Button() {
    return *(int*)((char*)this + 0x48);
}
