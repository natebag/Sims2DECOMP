// 0x80014280 (8 bytes)
class AwarenessManager {
public:
    int GetStateFlags();
};

int AwarenessManager::GetStateFlags() {
    return *(int*)((char*)this + 0x0);
}
