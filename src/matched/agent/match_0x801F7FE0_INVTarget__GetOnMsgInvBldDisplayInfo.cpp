// FLAGS: -fno-elide-constructors
typedef unsigned char u8;

extern char g_bldInfoFmt[16];
void setString3(char*, char*, ...);

void INVTarget_GetOnMsgInvBldDisplayInfo(u8* self, char* output) {
    int val = *(int*)(self + 0x32E4);
    int flag = 0;
    if (val != 0) flag = 1;
    setString3(output, g_bldInfoFmt, flag);
}
