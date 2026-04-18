// 0x801B8ACC (136B) H2DTarget::ReleasePause(bool) — MI-vcall at slot 10
class cSoundPlayer {
public:
    void SetGameMode(int);
    void ResumeSounds();
};

class PauseSingleton {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void Resume() = 0;
};

extern int g_PauseCount;
extern PauseSingleton* g_PauseSingleton;
extern cSoundPlayer* g_SoundPlayer;

void ReleasePause(bool setMode) {
    int count = g_PauseCount;
    if (count != 0) {
        int newCount = count - 1;
        g_PauseCount = newCount;
        if (newCount != 0) return;
    }
    if (g_PauseSingleton == 0) return;
    if (g_SoundPlayer == 0) return;
    if (setMode) {
        g_SoundPlayer->SetGameMode(1);
    }
    g_PauseSingleton->Resume();
    g_SoundPlayer->ResumeSounds();
}
