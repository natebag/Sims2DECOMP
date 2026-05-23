// FLAGS: -fno-elide-constructors
typedef unsigned char u8;

extern char g_shpInfoReadyFmt[16];
void setString2(char*, char*, ...);

void INVTarget_GetOnMsgInvShpObjectInfoReady(u8* self, char* output) {
    int val = *(int*)(self + 0x88);
    int flag = 0;
    if (val != 0) flag = 1;
    setString2(output, g_shpInfoReadyFmt, flag);
}
