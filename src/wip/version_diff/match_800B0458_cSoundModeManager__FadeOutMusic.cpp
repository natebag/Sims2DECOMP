class cSoundModeManager {
public:
    int pad_00;
    int m_musicFadeOutFlag;
    int pad_08;
    int m_musicFadeTime;

    void FadeOutMusic(unsigned int time);
};

void cSoundModeManager::FadeOutMusic(unsigned int time) {
    m_musicFadeTime = time;
    m_musicFadeOutFlag = 1;
}
