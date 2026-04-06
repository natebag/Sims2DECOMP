// 0x80095060 PreGameFreeplayState::Reset (44b)

extern void ResetFunc1(void);
extern int g_gameData[];
extern void UseConfigOptions(void*);

void PreGameFreeplayState_Reset(void) {
    ResetFunc1();
    UseConfigOptions((void*)g_gameData);
}
