class ERLevel;
class EEngine {
public:
    char m_pad[48];
    ERLevel *m_pCurrentLevel;
    void ClearCurrentLevel(ERLevel *);
};
void EEngine::ClearCurrentLevel(ERLevel *pLevel) {
    if (m_pCurrentLevel == pLevel) {
        m_pCurrentLevel = 0;
    }
}
