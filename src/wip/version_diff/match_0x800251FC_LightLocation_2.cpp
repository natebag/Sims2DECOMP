// FLAGS: -fno-schedule-insns
// FLAGS: -fno-schedule-insns
// 0x800251FC LightLocation (20b)
typedef unsigned char u8;
typedef unsigned short u16;

extern u8* g_lightMgr;
u8* lookupLight(u8*, unsigned int);

void LightLocation(unsigned int id, int flag, short* outX, short* outY) {
    *outY = (short)id;
    *outX = (short)id;
    u8* mgr = g_lightMgr;
    if (mgr == 0) return;
    unsigned int idx = id & 0xFFFF;
    if (idx > 0xFFFA) return;
    u8* result = lookupLight(mgr, idx);
    if (result != 0) {
        *outY = *(u16*)(result + 2);
    }
}
