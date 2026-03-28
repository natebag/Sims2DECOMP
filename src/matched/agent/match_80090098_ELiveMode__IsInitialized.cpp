// 0x80090098 (8 bytes)
class ELiveMode {
public:
    char pad[48];
    int m_initialized;

    int IsInitialized(void);
};

int ELiveMode::IsInitialized(void) {
    return m_initialized;
}
