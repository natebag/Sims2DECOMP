// 0x8001CAF8 (8 bytes) — lwz r3, 0x2D0(r3); blr

class CameraDirector {
public:
    char _pad[0x2D0];
    void* m_frameEffectsManager;

    void* GetFrameEffectsManager();
};

void* CameraDirector::GetFrameEffectsManager() {
    return m_frameEffectsManager;
}
