// FLAGS: -fno-schedule-insns -fno-schedule-insns2
typedef unsigned char u8;

extern char g_infoReadyFmt[16];
void setString(char*, char*, ...);

void INVTarget_GetOnMsgInvObjectInfoReady(u8* self, char* output) {
    int val = *(int*)(self + 0x88);
    int flag = 0;
    if (val != 0) flag = 1;
    setString(output, g_infoReadyFmt, flag);
}
