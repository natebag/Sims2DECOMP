struct cSoundPlayer {
    void SetGameMode(int);
    void ResumeSounds(void);
};

extern cSoundPlayer* g_pSoundPlayer;

void BGCall_SetGameModeAndResumeSounds(void)
{
    g_pSoundPlayer->SetGameMode(1);
    g_pSoundPlayer->ResumeSounds();
}

