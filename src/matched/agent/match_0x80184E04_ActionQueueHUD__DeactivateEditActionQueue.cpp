typedef unsigned char u8;

extern u8* g_sdaQueueMgr;

u8* removeFromQueue(u8*, int);
void destroyAction(u8*, int);

void ActionQueueHUD_DeactivateEditActionQueue(u8* self) {
    *(u8*)(self + 0x318) = 1;
    u8* mgr = (u8*)removeFromQueue(g_sdaQueueMgr, *(int*)(self + 0x314));
    destroyAction(mgr, *(int*)(self + 0x310));
    *(int*)(self + 0x310) = 0;
}
