// 0x8008395C (8 bytes)
class MUWrapper {
public:
    char pad[200];
    int m_backgroundDrawEnable;

    void SetBackgroundDrawEnable(int enable);
};

void MUWrapper::SetBackgroundDrawEnable(int enable) {
    m_backgroundDrawEnable = enable;
}
