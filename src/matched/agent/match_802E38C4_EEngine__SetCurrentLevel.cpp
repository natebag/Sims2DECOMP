class ERLevel;
class EEngine {
public:
    char m_pad[48];
    ERLevel *m_pCurrentLevel;
    void SetCurrentLevel(ERLevel *);
};
void EEngine::SetCurrentLevel(ERLevel *pLevel) { m_pCurrentLevel = pLevel; }
