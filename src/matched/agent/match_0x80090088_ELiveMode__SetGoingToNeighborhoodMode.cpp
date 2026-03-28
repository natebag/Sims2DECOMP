struct ELiveMode {
    char pad[0x24];
    int m_goingToNeighborhood;

    void SetGoingToNeighborhoodMode(int flag);
};

void ELiveMode::SetGoingToNeighborhoodMode(int flag) {
    m_goingToNeighborhood = flag;
}
