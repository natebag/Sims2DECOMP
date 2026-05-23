// 0x80042320 EGlobal::InLevelState(void) (24 B)
extern char g_levelStateInverted[];
struct EGlobal { int InLevelState(); };
int EGlobal::InLevelState() { return !(*(unsigned*)g_levelStateInverted ^ 1u); }
