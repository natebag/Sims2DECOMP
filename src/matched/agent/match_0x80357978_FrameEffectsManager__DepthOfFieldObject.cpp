struct FrameEffectsManager {
    char _p[0x08];
    int m_val;
    int DepthOfFieldObject();
};
int FrameEffectsManager::DepthOfFieldObject() { return m_val; }
