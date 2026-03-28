// 0x80014250 (8 bytes)
class AwarenessManager {
public:
    int GetAwareOfObject();
};

int AwarenessManager::GetAwareOfObject() {
    return *(int*)((char*)this + 0x1C);
}
