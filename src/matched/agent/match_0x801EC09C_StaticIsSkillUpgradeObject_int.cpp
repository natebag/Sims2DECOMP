// 0x801EC09C StaticIsSkillUpgradeObject(int) (52 B)

extern int g_skillUpgradeObjects[6];

int StaticIsSkillUpgradeObject(int type) {
    for (int i = 0; i < 6; i++) {
        if (g_skillUpgradeObjects[i] == type) {
            return 1;
        }
    }
    return 0;
}
