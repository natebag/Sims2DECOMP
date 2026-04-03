// 0x8007F06C (8 bytes)
class DlgWrapper {
public:
    int IsAptDrawable();
};

int DlgWrapper::IsAptDrawable() {
    return *(int*)((char*)this + 0xB4);
}
