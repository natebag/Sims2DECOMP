/* GameData::StageEnd(char *, char *, bool) at 0x8003DBE8 (80B) */

extern int g_loadingFlag1;
extern int g_loadingFlag2;

void LoadFinishing(void);

struct GameData {
    void StageEnd(char *name1, char *name2, int flag);
    void StageOutputActualTimes(char *name);
};

void GameData::StageEnd(char *name1, char *name2, int flag) {
    if (flag != 0) {
        g_loadingFlag1 = 1;
        g_loadingFlag2 = 1;
    }
    LoadFinishing();
    StageOutputActualTimes(name2);
}
