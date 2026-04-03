// 0x80014248 (8 bytes)
class AwarenessManager {
public:
    int GetAwarenessAction();
};

int AwarenessManager::GetAwarenessAction() {
    return *(int*)((char*)this + 0x18);
}
