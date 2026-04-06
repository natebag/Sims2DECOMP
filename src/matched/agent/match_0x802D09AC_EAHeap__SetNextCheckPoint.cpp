// 0x802D09AC EAHeap::SetNextCheckPoint (40b)

extern char g_checkpoint[4];
extern int GetCheckPoint(void);

void EAHeap_SetNextCheckPoint(void) {
    int val = GetCheckPoint();
    *(int*)g_checkpoint = val + 1;
}
