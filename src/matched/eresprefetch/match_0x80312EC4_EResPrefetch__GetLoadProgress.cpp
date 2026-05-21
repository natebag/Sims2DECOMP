// 0x80312EC4 (32B) EResPrefetch::GetLoadProgress(void)

extern float EResPrefetch_zeroProgress[3];  // 0x8042056C

class EResPrefetch {
public:
    float GetLoadProgress();
};

float EResPrefetch::GetLoadProgress() {
    if (*(int*)((char*)this + 1044) == 0) {
        return EResPrefetch_zeroProgress[0];
    }
    return *(float*)((char*)this + 1040);
}
