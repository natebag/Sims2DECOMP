// 0x802E38B8 (8 bytes)
class EEngine {
public:
    void EnableFrameRatePredictiveSmoothing(int p);
};

void EEngine::EnableFrameRatePredictiveSmoothing(int p) {
    *(int*)((char*)this + 0x8) = p;
}
