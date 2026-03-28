// 0x80014270 (8 bytes)
class AwarenessManager {
public:
    void SetTimeMultiplier(float p);
};

void AwarenessManager::SetTimeMultiplier(float p) {
    *(float*)((char*)this + 0x2C) = p;
}
