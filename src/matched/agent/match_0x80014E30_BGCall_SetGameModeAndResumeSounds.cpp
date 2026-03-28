/* BGCall_SetGameModeAndResumeSounds(void) at 0x80014E30 (48B) */

extern void* g_simulator;

void SetGameMode(void*, int);
void ResumeSounds(void*);

void BGCall_SetGameModeAndResumeSounds(void) {
    SetGameMode(g_simulator, 1);
    ResumeSounds(g_simulator);
}
