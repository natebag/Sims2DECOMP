// 0x80042320 EGlobal::InLevelState (24b)
extern int g_levelState[3];  /* 3-elem forces lis+lwz (not sda21) */

struct EGlobal {
    int InLevelState();
};

int EGlobal::InLevelState() {
    return g_levelState[0] == 1;
}
