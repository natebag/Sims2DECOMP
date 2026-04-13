// 0x800B0468 cSoundModeManager::FadeInMusic (12b)
// FLAGS: -fno-schedule-insns

class cSoundModeManager {
public:
    int pad_00;
    int pad_04;
    int m_musicFadeInFlag;
    int m_musicFadeTime;

    void FadeInMusic(unsigned int time);
};

void cSoundModeManager::FadeInMusic(unsigned int time) {
    int one = 1;
    *(volatile int*)&m_musicFadeTime = time;
    *(volatile int*)&m_musicFadeInFlag = one;
}
