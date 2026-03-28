// 0x80327EB4 (8 bytes)
class EResourceMap {
public:
    int GetMaxEntries();
};

int EResourceMap::GetMaxEntries() {
    return *(int*)((char*)this + 0x8);
}
