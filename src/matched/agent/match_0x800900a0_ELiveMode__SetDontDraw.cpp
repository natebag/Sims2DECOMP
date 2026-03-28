struct ELiveMode {
    char pad[0x34];
    int m_dontDraw;

    void SetDontDraw(int flag);
};

void ELiveMode::SetDontDraw(int flag) {
    m_dontDraw = flag;
}
