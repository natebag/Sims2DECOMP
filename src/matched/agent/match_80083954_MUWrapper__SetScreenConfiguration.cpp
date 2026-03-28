// 0x80083954 (8 bytes)
class MUWrapper {
public:
    int pad[43];
    int m_screenConfiguration;

    void SetScreenConfiguration(int config);
};

void MUWrapper::SetScreenConfiguration(int config) {
    m_screenConfiguration = config;
}
