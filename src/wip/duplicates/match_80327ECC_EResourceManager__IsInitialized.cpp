// 0x80327ECC (8 bytes)
class EResourceManager {
public:
    int IsInitialized();
};

int EResourceManager::IsInitialized() {
    return *(int*)((char*)this + 0x48);
}
