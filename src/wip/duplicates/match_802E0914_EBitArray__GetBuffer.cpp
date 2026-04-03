// 0x802E0914 (8 bytes)
class EBitArray {
public:
    int GetBuffer();
};

int EBitArray::GetBuffer() {
    return *(int*)((char*)this + 0x0);
}
