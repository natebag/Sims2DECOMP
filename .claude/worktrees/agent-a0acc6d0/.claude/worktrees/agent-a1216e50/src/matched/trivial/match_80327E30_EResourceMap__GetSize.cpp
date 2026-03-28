// 0x80327E30 (8 bytes)
class EResourceMap {
public:
    int GetSize();
};

int EResourceMap::GetSize() {
    return *(int*)((char*)this + 0x4);
}
