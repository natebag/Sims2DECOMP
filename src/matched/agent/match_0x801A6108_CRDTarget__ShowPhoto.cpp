/* CRDTarget::ShowPhoto(void) at 0x801A6108 (128b) */

extern void WidgetInit(void*);
extern void WidgetReset(void*);
extern void WidgetSetName(void*, char*, int);
extern void WidgetSetVisible(void*, int);
extern void WidgetSetWidth(void*, int);
extern void WidgetShow(void*);
extern void WidgetFinish(void*, int);

extern char g_photoName[];

struct CRDTarget {
    char pad[0x94];
    int m_photoState;

    void ShowPhoto();
};

void CRDTarget::ShowPhoto() {
    char local[24];
    WidgetInit(&local);
    WidgetReset(&local);
    WidgetSetName(&local, g_photoName, 0);
    WidgetSetVisible(&local, 1);
    WidgetSetWidth(&local, 640);
    WidgetShow(&local);
    m_photoState = 0;
    WidgetFinish(&local, 2);
}
