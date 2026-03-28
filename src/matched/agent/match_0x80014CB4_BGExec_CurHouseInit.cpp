/* BGExec_CurHouseInit(void) at 0x80014CB4 (48B) */

extern int* g_curHouseArray[];
extern int g_bgDone;

void CurHouseInit(int*);

void BGExec_CurHouseInit(void) {
    CurHouseInit(g_curHouseArray[0]);
    g_bgDone = 1;
}
