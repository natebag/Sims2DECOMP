// 0x80014278 (8 bytes)
class AwarenessManager {
public:
    void SetPauseMultiplier(float p);
};

void AwarenessManager::SetPauseMultiplier(float p) {
    *(float*)((char*)this + 0x30) = p;
}
