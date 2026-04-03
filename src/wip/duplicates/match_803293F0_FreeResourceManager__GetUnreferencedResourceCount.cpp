// 0x803293F0 (8 bytes)
class FreeResourceManager {
public:
    int GetUnreferencedResourceCount();
};

int FreeResourceManager::GetUnreferencedResourceCount() {
    return *(int*)((char*)this + 0xCA0);
}
