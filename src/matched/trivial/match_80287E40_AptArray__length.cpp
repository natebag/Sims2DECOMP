// 0x80287E40 (8 bytes)
class AptArray {
public:
    int length();
};

int AptArray::length() {
    return *(int*)((char*)this + 0x2C);
}
