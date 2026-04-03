// 0x8009FF4C (8 bytes)
class BString {
public:
    int length();
};

int BString::length() {
    return *(int*)((char*)(*(int*)((char*)this + 0x0)) + 0x4);
}
