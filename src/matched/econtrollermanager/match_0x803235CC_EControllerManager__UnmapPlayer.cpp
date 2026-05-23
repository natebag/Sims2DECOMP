struct EControllerManager {
    char _p[0x10];
    int m_playerMapped[4];
    void UnmapPlayer(unsigned int i);
};
void EControllerManager::UnmapPlayer(unsigned int i) { m_playerMapped[i] = 0; }
