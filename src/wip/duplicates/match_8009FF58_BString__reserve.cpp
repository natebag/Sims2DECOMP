// 0x8009FF58 (8 bytes)
class BString {
public:
    int reserve();
};

int BString::reserve() {
    return *(int*)((char*)(*(int*)((char*)this + 0x0)) + 0x8);
}
