// 0x800900A0 (8 bytes)
class ELiveMode {
public:
    char pad[52];
    int m_dontDraw;

    void SetDontDraw(int flag);
};

void ELiveMode::SetDontDraw(int flag) {
    m_dontDraw = flag;
}
