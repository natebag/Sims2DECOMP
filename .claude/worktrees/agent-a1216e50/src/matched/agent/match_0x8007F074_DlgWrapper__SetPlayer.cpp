/* 0x8007F074 (16 bytes) - DlgWrapper::SetPlayer(int) */
class DlgWrapper {
public:
    char pad[0xCC];
    int m_player;
    int SetPlayer(int p);
};

int DlgWrapper::SetPlayer(int p) {
    int old = m_player;
    m_player = p;
    return old;
}
