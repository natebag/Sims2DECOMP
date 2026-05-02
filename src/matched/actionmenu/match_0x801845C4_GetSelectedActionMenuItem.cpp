// 0x801845C4 GetSelectedActionMenuItem(unsigned int) (32B)

extern int g_SelectedActionMenuItems[2];

int GetSelectedActionMenuItem(unsigned int arg) {
    if (arg <= 1) return g_SelectedActionMenuItems[arg];
    return 0;
}
