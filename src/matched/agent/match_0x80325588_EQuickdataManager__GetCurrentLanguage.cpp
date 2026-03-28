struct EQuickdataManager {
    char _p[0xd20];
    int m_currentLanguage;
    int GetCurrentLanguage() const;
};
int EQuickdataManager::GetCurrentLanguage() const { return m_currentLanguage; }
