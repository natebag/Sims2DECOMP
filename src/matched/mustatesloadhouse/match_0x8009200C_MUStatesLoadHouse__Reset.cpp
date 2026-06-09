struct MUStatesLoadHouse {
    char pad[0x1C];
    int m_state;

    void Reset(void);
};

void MUStatesLoadHouse::Reset(void) {
    m_state = 0;
}
