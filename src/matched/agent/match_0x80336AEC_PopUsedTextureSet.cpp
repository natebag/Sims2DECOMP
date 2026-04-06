// FLAGS: -msdata=eabi -G 8
// 0x80336AEC PopUsedTextureSet (64b)
extern int OSReceiveMessage(char* queue, int* msg, int flags);
extern char g_usedTexQueue[];

int PopUsedTextureSet() {
    int msg;
    if (OSReceiveMessage(g_usedTexQueue, &msg, 0) == 1) {
        return msg;
    }
    return 0;
}
