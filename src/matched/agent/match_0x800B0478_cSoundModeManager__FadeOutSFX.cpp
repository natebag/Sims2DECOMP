// 0x800B0478 cSoundModeManager::FadeOutSFX (16b)
// FLAGS: -fno-schedule-insns
typedef unsigned int uint;

struct cSoundModeManager {
    char _pad[28];
};

void cSoundModeManager__FadeOutSFX(cSoundModeManager *self, uint duration) {
    *(uint *)((char *)self + 24) = duration;
    *(uint *)((char *)self + 16) = 1;
}
