// 0x80093118 (12 bytes)
class MUStatesLoadConfig {
public:
    char pad[28];
    int m_state;

    void Reset(void);
};

void MUStatesLoadConfig::Reset(void) {
    m_state = 0;
}
