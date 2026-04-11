class cSoundModeManager {
public:
    int pad_00;
    int pad_04;
    int m_musicFadeInFlag;
    int m_musicFadeTime;

    void FadeInMusic(unsigned int time);
};

void cSoundModeManager::FadeInMusic(unsigned int time) {
    m_musicFadeTime = time;
    m_musicFadeInFlag = 1;
}
