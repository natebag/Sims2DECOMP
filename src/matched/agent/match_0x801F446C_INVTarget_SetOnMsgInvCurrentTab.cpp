// FLAGS: -fno-elide-constructors
// 0x801F446C (88 bytes)
// INVTarget::SetOnMsgInvCurrentTab(char *)

extern "C" int atoi_func(char* str);
extern "C" void funcA(void* self, int val);
extern "C" void funcB(void* self);
extern int g_tabGlobal[4]; // >8 bytes forces non-SDA (lis+lwz)

void INVTarget_SetOnMsgInvCurrentTab(void* self, char* str) {
    int val = atoi_func(str);
    if (g_tabGlobal[0] != 0) {
        funcA(self, val);
    } else {
        funcB(self);
    }
}
