// 0x80091B78 (12 bytes)
class MUStatesLoadGame {
public:
    char pad[28];
    int m_state;

    void Reset(void);
};

void MUStatesLoadGame::Reset(void) {
    m_state = 0;
}
