// 0x800A017C (8 bytes)
class BString2 {
public:
    int point();
};

int BString2::point() {
    return *(int*)((char*)(*(int*)((char*)this + 0x0)) + 0x0);
}
