class HUDTarget {
public:
    char _pad[0x100];
    unsigned char m_field_100;

    void RequestQuitGame(bool quitRequested);
};

void HUDTarget::RequestQuitGame(bool quitRequested) {
    if (quitRequested) {
        m_field_100 = 1;
        return;
    }
    m_field_100 = quitRequested;
}
