// 0x801B8A40 (140B) H2DTarget::IncPause(bool) — MI-vcall at slot 10
class cSoundPlayer {
public:
    void PauseSounds();
    void SetGameMode(int);
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
    virtual void Pause() = 0;
};

extern int g_PauseCount;
extern PauseSingleton* g_PauseSingleton;
extern cSoundPlayer* g_SoundPlayer;

void IncPause(bool setMode) {
    if (g_PauseCount == 0 && g_PauseSingleton != 0 && g_SoundPlayer != 0) {
        g_PauseSingleton->Pause();
        g_SoundPlayer->PauseSounds();
        if (setMode) {
            g_SoundPlayer->SetGameMode(6);
        }
    }
    g_PauseCount++;
}
