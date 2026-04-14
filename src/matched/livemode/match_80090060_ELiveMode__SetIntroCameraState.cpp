// 0x80090060 (8 bytes)
class ELiveMode {
public:
    char pad[12];
    int m_introCameraState;

    void SetIntroCameraState(int state);
};

void ELiveMode::SetIntroCameraState(int state) {
    m_introCameraState = state;
}
