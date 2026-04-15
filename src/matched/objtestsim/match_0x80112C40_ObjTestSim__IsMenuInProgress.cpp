/* ObjTestSim::IsMenuInProgress(void) - 0x80112C40 (48 bytes) */

extern int g_MenuInProgressA;
extern int g_MenuInProgressB;
extern int g_MenuInProgressC;

class ObjTestSim {
public:
    static int IsMenuInProgress(void);
};

int ObjTestSim::IsMenuInProgress(void) {
    int r = 0;
    if (g_MenuInProgressA != 0) {
        if (g_MenuInProgressB != 0) {
            if (g_MenuInProgressC != 0) {
                r = 1;
            }
        }
    }
    return r;
}
