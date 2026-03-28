/* ACTTarget::CancellingLastObject(void) at 0x801A311C (168b) */

extern void WidgetInit(void*);
extern void WidgetReset(void*);
extern void WidgetSetName(void*, char*, int);
extern void WidgetSetColor(void*, unsigned int);
extern void WidgetShow(void*);
extern void WidgetFinish(void*, int);

extern void* AllocMem(int);
extern void* CreateObj();
extern void SetObjName(void*, unsigned int);

struct ACTTarget {
    char pad_00[0xDC];
    int m_someId;
    char pad_E0[0x04];
    int m_fieldE4;
    void* m_object;

    void CancellingLastObject();
};

extern void* g_actGlobal;

void ACTTarget::CancellingLastObject() {
    if (m_object == 0) return;

    char local[24];
    WidgetInit(&local);
    WidgetReset(&local);
    WidgetSetName(&local, *(char**)((char*)m_object + 44), m_someId);
    WidgetSetColor(&local, 0x00FF6666);
    WidgetShow(&local);
    if (g_actGlobal == 0) {
        void* mem = AllocMem(120);
        g_actGlobal = CreateObj();
    }
    SetObjName(g_actGlobal, 0x048AE94F);
    WidgetFinish(&local, 2);
}
