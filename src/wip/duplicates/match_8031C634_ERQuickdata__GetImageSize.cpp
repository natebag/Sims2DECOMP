// 0x8031C634 (8 bytes)
class ERQuickdata {
public:
    int GetImageSize();
};

int ERQuickdata::GetImageSize() {
    return *(int*)((char*)this + 0x18);
}
