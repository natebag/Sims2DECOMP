class EEngine {
public:
    char m_pad[8];
    int m_frameRatePredictiveSmoothing;
    void EnableFrameRatePredictiveSmoothing(bool);
};
void EEngine::EnableFrameRatePredictiveSmoothing(bool enable) { m_frameRatePredictiveSmoothing = enable; }
