// 0x8031C62C (8 bytes)
class ERQuickdata {
public:
    int GetImage();
};

int ERQuickdata::GetImage() {
    return *(int*)((char*)this + 0x14);
}
