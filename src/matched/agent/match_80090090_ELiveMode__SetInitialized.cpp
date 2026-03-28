// 0x80090090 (8 bytes)
class ELiveMode {
public:
    char pad[48];
    int m_initialized;

    void SetInitialized(int flag);
};

void ELiveMode::SetInitialized(int flag) {
    m_initialized = flag;
}
