// FLAGS: -msdata=eabi -G 8
// 0x80337834 PopDecodedAudioBuffer (64b)
extern int OSReceiveMessage(char* queue, int* msg, int timeout);
extern char g_decodedAudioQueue[];

int PopDecodedAudioBuffer(int timeout) {
    int msg;
    if (OSReceiveMessage(g_decodedAudioQueue, &msg, timeout) == 1) {
        return msg;
    }
    return 0;
}
