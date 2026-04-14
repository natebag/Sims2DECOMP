// 0x800B7A60 cSoundPlayer::PlayBySource(char*, short) (108B)
// Pattern: 4x guard + EResourceManager::CalcId(name) + delegate to PlayBySource(uint, short)
namespace EResourceManager {
    unsigned int CalcId(char* name);
}

struct cSoundPlayer {
    int m_f0;
    int m_f4;
    int m_f8;
    void PlayBySource(unsigned int id, short prio);
    void PlayBySource(char* name, short prio);
};

void cSoundPlayer::PlayBySource(char* name, short prio) {
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    if (name == 0) return;
    if (prio == -2) return;
    unsigned int id = EResourceManager::CalcId(name);
    PlayBySource(id, prio);
}
