// 0x80092B08 (12 bytes)
class MUStatesSaveExistingGame {
public:
    char pad[28];
    int m_state;

    void Reset(void);
};

void MUStatesSaveExistingGame::Reset(void) {
    m_state = 0;
}
