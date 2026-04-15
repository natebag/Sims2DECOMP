/* ELiveMode::IsIntroCameraTriggered(void) - 0x80090040 (20 bytes) */

class ELiveMode {
public:
    char pad[12];
    int m_introCamState;  // +12

    int IsIntroCameraTriggered(void);
};

int ELiveMode::IsIntroCameraTriggered(void) {
    return m_introCamState == 1;
}
