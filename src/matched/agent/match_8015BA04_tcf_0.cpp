/* __tcf_0 at 0x8015BA04 (40B) - static destructor */

extern int g_staticObj;
extern void DestroyFunc(int*, int);

void tcf_0() {
    DestroyFunc(&g_staticObj, 2);
}
