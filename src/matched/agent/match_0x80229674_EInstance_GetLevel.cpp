struct EInstance {
    char _pad[0x04];
    int m_GetLevel;
    int GetLevel();
};
int EInstance::GetLevel() { return m_GetLevel; }
