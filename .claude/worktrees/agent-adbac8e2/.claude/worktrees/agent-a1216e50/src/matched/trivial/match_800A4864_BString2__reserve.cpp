// 0x800A4864 (8 bytes)
class BString2 {
public:
    int reserve();
};

int BString2::reserve() {
    return *(int*)((char*)(*(int*)((char*)this + 0x0)) + 0x8);
}
