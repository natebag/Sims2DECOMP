// 0x800B0458 cSoundModeManager::FadeOutMusic (16b)
// FLAGS: -fno-schedule-insns
typedef unsigned int uint;

struct cSoundModeManager {
    char _pad[28];
};

void cSoundModeManager__FadeOutMusic(cSoundModeManager *self, uint duration) {
    *(uint *)((char *)self + 12) = duration;
    *(uint *)((char *)self + 4) = 1;
}
