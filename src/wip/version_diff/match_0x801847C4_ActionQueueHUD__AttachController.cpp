// VERSION_DIFF: 1-instruction scheduling swap (lis+addi interleaving)
typedef unsigned char u8;

extern u8* g_sdaQueueMgr3;
extern char g_attachStr[16];
u8* getQueueMgr(u8*, int);
u8* createAction(u8*, int, char*, int);

void ActionQueueHUD_AttachController(u8* self) {
    if (*(int*)(self + 0x30C) != 0) return;
    u8* mgr = getQueueMgr(g_sdaQueueMgr3, *(int*)(self + 0x314));
    u8* action = createAction(mgr, 0, g_attachStr, 100);
    *(int*)(self + 0x30C) = (int)action;
}
