// 0x800B0458 cSoundModeManager::FadeOutMusic (12b)
// FLAGS: -fno-schedule-insns

class cSoundModeManager {
public:
    int pad_00;
    int m_musicFadeOutFlag;
    int pad_08;
    int m_musicFadeTime;

    void FadeOutMusic(unsigned int time);
};

void cSoundModeManager::FadeOutMusic(unsigned int time) {
    int one = 1;
    *(volatile int*)&m_musicFadeTime = time;
    *(volatile int*)&m_musicFadeOutFlag = one;
}
