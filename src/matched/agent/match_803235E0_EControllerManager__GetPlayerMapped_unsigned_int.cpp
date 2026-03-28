class EControllerManager { char pad[16]; int m_playerMapped[4]; public: int GetPlayerMapped(unsigned int); };
int EControllerManager::GetPlayerMapped(unsigned int idx) { return m_playerMapped[idx]; }
