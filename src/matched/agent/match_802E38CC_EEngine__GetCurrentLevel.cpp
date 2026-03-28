class ERLevel;
class EEngine {
public:
    char m_pad[48];
    ERLevel *m_pCurrentLevel;
    ERLevel *GetCurrentLevel();
};
ERLevel *EEngine::GetCurrentLevel() { return m_pCurrentLevel; }
