// 0x8009C064 (8 bytes)
class BString {
public:
    int point();
};

int BString::point() {
    return *(int*)((char*)(*(int*)((char*)this + 0x0)) + 0x0);
}
