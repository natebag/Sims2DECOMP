// 0x80090088 (8 bytes)
class ELiveMode {
public:
    char pad[36];
    int m_goingToNeighborhoodMode;

    void SetGoingToNeighborhoodMode(int flag);
};

void ELiveMode::SetGoingToNeighborhoodMode(int flag) {
    m_goingToNeighborhoodMode = flag;
}
