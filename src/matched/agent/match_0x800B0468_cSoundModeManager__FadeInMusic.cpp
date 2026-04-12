// 0x800B0468 cSoundModeManager::FadeInMusic (16b)
// FLAGS: -fno-schedule-insns
typedef unsigned int uint;

struct cSoundModeManager {
    char _pad[28];
};

void cSoundModeManager__FadeInMusic(cSoundModeManager *self, uint duration) {
    *(uint *)((char *)self + 12) = duration;
    *(uint *)((char *)self + 8) = 1;
}
