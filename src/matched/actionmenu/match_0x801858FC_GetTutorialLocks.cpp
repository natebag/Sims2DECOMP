// 0x801858FC GetTutorialLocks(int) (32B)

extern unsigned char g_TutorialLocks[8];

unsigned int GetTutorialLocks(int arg) {
    unsigned int r = 0;
    arg++;
    if (arg <= 7) r = g_TutorialLocks[arg];
    return r;
}
