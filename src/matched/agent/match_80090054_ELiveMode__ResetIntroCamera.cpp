// 0x80090054 (12 bytes)
class ELiveMode {
public:
    char pad[12];
    int m_introCameraState;

    void ResetIntroCamera(void);
};

void ELiveMode::ResetIntroCamera(void) {
    m_introCameraState = 0;
}
