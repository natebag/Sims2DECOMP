// 0x802E076C (8 bytes)
class EBitArray {
public:
    int GetSize();
};

int EBitArray::GetSize() {
    return *(int*)((char*)this + 0x4);
}
