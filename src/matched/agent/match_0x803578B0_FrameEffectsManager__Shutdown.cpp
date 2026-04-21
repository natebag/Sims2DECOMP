// 0x803578B0 (184B) FrameEffectsManager::Shutdown(void)
// 3x MI vcall Release(3) + null: m_mb (offset 0), m_bloom (offset 4), m_dof (offset 8).
// Each target has 16B non-virtual base, vtable at offset 16 slot 1 = Release.

class FrameEffectBase {
protected:
    char pad[16];
};

class FrameEffect : public FrameEffectBase {
public:
    virtual void Release(int flags) = 0;
};

class FrameEffectsManager {
public:
    FrameEffect* m_motionBlur;
    FrameEffect* m_bloom;
    FrameEffect* m_depthOfField;
    void Shutdown();
};

void FrameEffectsManager::Shutdown() {
    if (m_motionBlur) {
        m_motionBlur->Release(3);
        m_motionBlur = 0;
    }
    if (m_bloom) {
        m_bloom->Release(3);
        m_bloom = 0;
    }
    if (m_depthOfField) {
        m_depthOfField->Release(3);
        m_depthOfField = 0;
    }
}
