// 0x80327EBC (8 bytes)
class EResourceMap {
public:
    int GetMaxLoaded();
};

int EResourceMap::GetMaxLoaded() {
    return *(int*)((char*)this + 0xC);
}
