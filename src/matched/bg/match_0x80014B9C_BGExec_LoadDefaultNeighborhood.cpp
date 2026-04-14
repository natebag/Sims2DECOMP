/* BGExec_LoadDefaultNeighborhood(void) at 0x80014B9C (48B) */

extern char g_simsAppBG[];
extern int g_bgDone;

void LoadDefaultNeighborhood(void*);

void BGExec_LoadDefaultNeighborhood(void) {
    LoadDefaultNeighborhood(g_simsAppBG);
    g_bgDone = 1;
}
