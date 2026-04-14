// 0x80090068 (8 bytes)
class ELiveMode {
public:
    char pad[12];
    int m_introCameraState;

    int GetIntroCameraState(void);
};

int ELiveMode::GetIntroCameraState(void) {
    return m_introCameraState;
}
