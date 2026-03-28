struct EControllerManager {
    char _p[0x10];
    int m_playerMapped[4];
    int GetPlayerMapped(unsigned int i);
};
int EControllerManager::GetPlayerMapped(unsigned int i) { return m_playerMapped[i]; }
