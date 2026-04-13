// 0x8015BA04 __tcf_0 (40b)

extern int g_staticObj;
extern void DestroyFunc(int*, int);

void tcf_0() {
    DestroyFunc(&g_staticObj, 2);
}
