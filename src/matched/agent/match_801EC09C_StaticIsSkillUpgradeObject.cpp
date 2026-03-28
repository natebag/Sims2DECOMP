extern int g_skillUpgradeObjects[6];

int StaticIsSkillUpgradeObject(int id) {
    int i;
    for (i = 0; i < 6; i++) {
        if (g_skillUpgradeObjects[i] == id) {
            return 1;
        }
    }
    return 0;
}
