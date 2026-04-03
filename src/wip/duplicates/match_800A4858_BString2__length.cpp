// 0x800A4858 (8 bytes)
class BString2 {
public:
    int length();
};

int BString2::length() {
    return *(int*)((char*)(*(int*)((char*)this + 0x0)) + 0x4);
}
