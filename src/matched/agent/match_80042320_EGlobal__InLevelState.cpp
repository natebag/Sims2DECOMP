extern char g_levelState[];
int EGlobal_InLevelState() {
    int val = *(int*)g_levelState;
    return (val ^ 1) == 0;
}
