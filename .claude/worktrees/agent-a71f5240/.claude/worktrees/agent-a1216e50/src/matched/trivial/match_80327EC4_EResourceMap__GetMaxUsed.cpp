// 0x80327EC4 (8 bytes)
class EResourceMap {
public:
    int GetMaxUsed();
};

int EResourceMap::GetMaxUsed() {
    return *(int*)((char*)this + 0x10);
}
