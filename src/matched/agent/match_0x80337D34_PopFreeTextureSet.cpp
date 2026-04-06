// FLAGS: -msdata=eabi -G 8
// 0x80337D34 PopFreeTextureSet (52b)
extern int OSReceiveMessage(char* queue, int* msg, int flags);
extern char g_freeTexQueue[];

int PopFreeTextureSet() {
    int msg;
    OSReceiveMessage(g_freeTexQueue, &msg, 1);
    return msg;
}
