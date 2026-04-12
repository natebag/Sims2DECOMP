// 0x800B0488 cSoundModeManager::FadeInSFX (16b)
// FLAGS: -fno-schedule-insns
typedef unsigned int uint;

struct cSoundModeManager {
    char _pad[28];
};

void cSoundModeManager__FadeInSFX(cSoundModeManager *self, uint duration) {
    *(uint *)((char *)self + 24) = duration;
    *(uint *)((char *)self + 20) = 1;
}
