typedef unsigned char u8;

extern u8* g_sdaQueueMgr2;
u8* removeFromQueue2(u8*, int);
void destroyAction2(u8*, int);

void ActionQueueHUD_DetachController(u8* self) {
    if (*(int*)(self + 0x30C) == 0) return;
    u8* mgr = removeFromQueue2(g_sdaQueueMgr2, *(int*)(self + 0x314));
    destroyAction2(mgr, *(int*)(self + 0x30C));
    *(int*)(self + 0x30C) = 0;
}
