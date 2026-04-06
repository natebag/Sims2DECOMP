// FLAGS: -msdata=eabi -G 8
// 0x80337D98 PopDecodedTextureSet (64b)
extern int OSReceiveMessage(char* queue, int* msg, int timeout);
extern char g_decodedTexQueue[];

int PopDecodedTextureSet(int timeout) {
    int msg;
    if (OSReceiveMessage(g_decodedTexQueue, &msg, timeout) == 1) {
        return msg;
    }
    return 0;
}
