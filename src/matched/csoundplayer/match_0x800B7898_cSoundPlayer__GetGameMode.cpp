/* cSoundPlayer::GetGameMode(void) - 0x800B7898 (24 bytes) */

struct SndEngine {
    char pad[48];
    int m_gameMode;
};

extern SndEngine* g_SndEngine;

class cSoundPlayer {
public:
    static int GetGameMode(void);
};

int cSoundPlayer::GetGameMode(void) {
    SndEngine* e = g_SndEngine;
    if (e == 0) return 3;
    return e->m_gameMode;
}
