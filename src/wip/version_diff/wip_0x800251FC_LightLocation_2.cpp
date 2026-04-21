// PARTIAL-FAKE from full-tree verify sweep 2026-04-21.
// Moved from src/matched/agent/match_0x800251FC_LightLocation_2.cpp.
// Declared 20B in file header, map shows 104B — file body does not
// produce byte-match at map size 104B.
//
// Root cause: bad extern shape. DOL uses SDA lwz; file declares plain
// `extern u8* g_lightMgr` instead of properly-sized extern form that
// forces SDA21 relocation. Filename suffix `_2` suggests stale duplicate
// from an earlier attempt that was never reconciled with the true
// 104B function shape.
//
// See OpusReview info board legacy-mislabels audit.

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
