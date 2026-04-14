// 0x80090038 (8 bytes)
class ELiveMode {
public:
    char pad[40];
    int m_transportMode;

    int InTransportMode(void);
};

int ELiveMode::InTransportMode(void) {
    return m_transportMode;
}
