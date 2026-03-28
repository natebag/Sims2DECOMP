static int s_forceReadDone;
typedef struct DVDFileInfo DVDFileInfo;
void ForceReadCallback(long, DVDFileInfo *) { s_forceReadDone = 1; }
