// 0x8007E5E0 (8 bytes)
class DlgWrapper {
public:
    int GetFont();
};

int DlgWrapper::GetFont() {
    return *(int*)((char*)this + 0xA8);
}
