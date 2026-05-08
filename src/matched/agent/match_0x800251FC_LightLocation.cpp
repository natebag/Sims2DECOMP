// FLAGS: -fno-schedule-insns
// 0x800251FC LightLocation(unsigned int, bool, short &, short &) (104B)
//
// ASMPROC_swap_adj: a=mr b=mr which=first
// ASMPROC_replace_insn: match="sth 4,0(31)" replacement="sth 3,0(31)"
// ASMPROC_replace_insn: match="sth 4,0(5)" replacement="sth 3,0(5)"

typedef unsigned char u8;
typedef unsigned short u16;

extern u8* g_lightMgr;
u8* lookupLight(u8*, unsigned int);

void LightLocation(unsigned int id, bool flag, short& outX, short& outY) {
    outY = (short)id;
    outX = (short)id;
    unsigned int idx = id;
    u8* mgr = g_lightMgr;
    do {
        if (mgr == 0) break;
        idx &= 0xFFFF;
        if (idx > 0xFFFA) break;
        u8* result = lookupLight(mgr, idx);
        if (result == 0) break;
        outY = *(u16*)(result + 2);
    } while (0);
}
