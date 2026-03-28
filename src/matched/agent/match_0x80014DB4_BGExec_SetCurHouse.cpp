/* BGExec_SetCurHouse(void) at 0x80014DB4 (52B) */

extern char g_simsAppBG2[];
extern int g_bgDone;

void SetCurHouse(void*, int);

void BGExec_SetCurHouse(void) {
    char* app = g_simsAppBG2;
    int houseId = *(int*)(app + 0x464);
    SetCurHouse(app, houseId);
    g_bgDone = 1;
}
