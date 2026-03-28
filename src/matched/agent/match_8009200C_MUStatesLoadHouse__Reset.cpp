// 0x8009200C (12 bytes)
class MUStatesLoadHouse {
public:
    char pad[28];
    int m_state;

    void Reset(void);
};

void MUStatesLoadHouse::Reset(void) {
    m_state = 0;
}
